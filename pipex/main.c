/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:45:16 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/29 14:55:28 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>

char	***get_commands(int argc, char **argv);
char	*get_path(char **envp, char *cmd);

void execute_command(char **cmd, t_pipex *pipex) {
	char *path;
    path = get_path(pipex->envp, cmd[0]);

	if (execve(path, cmd, pipex->envp) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

void pipe_exec(t_pipex *pipex) {
    int pipefd[2];
    int pid;
    char buffer[4096]; // Buffer to store data read from the pipe
    ssize_t bytes_read;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
		if (pipex->cmd_index == 0)
		{
			dup2(pipex->in_fd, STDIN_FILENO);
			close(pipex->in_fd);
			close(pipefd[0]);

			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[1]);
			execute_command(pipex->cmds[pipex->cmd_index], pipex);
		}
		else
		{
			pipex->cmd_index--;
			pipe_exec(pipex);
		}

    } else { // Parent process
		close(pipefd[1]); // Close the front end of the pipe
		waitpid(pid, NULL, 0);
		if (pipex->cmd_index == pipex->cmds_count - 1)
		{

			// Read from the pipe and print
			while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0) {
				buffer[bytes_read] = '\0'; // Null-terminate the string
				if (write(pipex->out_fd, buffer, bytes_read) == -1) {
				perror("write");
				close(pipex->out_fd);
				exit(EXIT_FAILURE);
				}
			}
			close(pipefd[0]); // Close the read end of the pipe
		}
		else {
			dup2(pipefd[0], STDIN_FILENO);
			execute_command(pipex->cmds[pipex->cmd_index], pipex);
		}
    }
}

int main(int argc, char **argv, char **envp) {
	struct s_pipex *pipex;
	int pid;

	if (argc < 4)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd... outfile\n", 2);
		exit(1);
	}

	pipex = malloc(sizeof(t_pipex));
	pipex->in_fd = open(argv[1], O_RDONLY);
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex->cmds = get_commands(argc, argv);
	pipex->cmds_count = argc - 3;
	pipex->cmd_index = pipex->cmds_count - 1;
	pipex->envp = envp;

	pid = fork();
	if (pid == 0)
    	pipe_exec(pipex);
	waitpid(pid, NULL, 0);
    return 0;
}

char	***get_commands(int argc, char **argv)
{
	char ***cmds;
	int i = 0;

	cmds = (char ***)malloc(sizeof(char **) * (argc - 2));
	while ((i + 2) < argc - 1)
	{
		cmds[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

char	*get_path(char **envp, char *cmd)
{
	char	**paths;
	char	*path;
	char	*tmp;

	path = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			paths = ft_split(ft_strchr(*envp, '/'), ':');
			while (paths)
			{
				tmp = ft_strjoin(*paths, "/");
				tmp = ft_strjoin(tmp, cmd);

				if (access(tmp, X_OK) == 0)
				{
					path = tmp;
					break ;
				}
				else
					paths++;
			}
		}
		envp++;
	}
	return (path);
}
