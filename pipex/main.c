/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:45:16 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/29 16:35:37 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>

char	***get_commands(int argc, char **argv);
char	*get_path(char **envp, char *cmd);
int comands_is_valid(char **envp, char ***cmds);
void free_pipex(t_pipex *pipex);


void execute_command(char **cmd, t_pipex *pipex) {
	char *path;
    path = get_path(pipex->envp, cmd[0]);
	if (path == NULL)
	{
        perror("path");
        exit(EXIT_FAILURE);
	}
	else
	{
		if (execve(path, cmd, pipex->envp) == -1) {
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
}

void pipe_exec(t_pipex *pipex) {
    int pipefd[2];
    int pid;

    // Create a pipe

	if (pipex->cmd_index > 0)
	{
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
			{
				close(pipefd[0]);
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[1]);
				pipex->cmd_index--;
				pipe_exec(pipex);
			}
		} else { // Parent process
			close(pipefd[1]); // Close the front end of the pipe
			waitpid(pid, NULL, 0);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			execute_command(pipex->cmds[pipex->cmd_index], pipex);
		}
	}
		execute_command(pipex->cmds[pipex->cmd_index], pipex);
}

int main(int argc, char **argv, char **envp) {
	struct s_pipex *pipex;
	int pid;
	int pipefd[2];
	char buffer[4096]; // Buffer to store data read from the pipe
    ssize_t bytes_read;

	if (argc < 4)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd... outfile\n", 2);
		exit(1);
	}
	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
	{
		perror("malloc");
		exit(1);
	}
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
	{
		perror("open infile");
		exit(1);
	}
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->out_fd == -1)
	{
		perror("open outfile");
		exit(1);
	}
	pipex->cmds = get_commands(argc, argv);
	if (!comands_is_valid(envp, pipex->cmds))
		exit(1);
	pipex->cmds_count = argc - 3;
	pipex->cmd_index = pipex->cmds_count - 1;
	pipex->envp = envp;

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

	if (pid == 0)
	{
			dup2(pipex->in_fd, STDIN_FILENO);
			close(pipex->in_fd);
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[1]);
			pipe_exec(pipex);
	}
	else
	{
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
			close(pipex->out_fd);
		}
	}
	free_pipex(pipex);
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
			while (paths != NULL && *paths != NULL)
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
			break;
		}
		envp++;
	}
	return (path);
}

int comands_is_valid(char **envp, char ***cmds)
{
	int i = 0;
	char *path = NULL;

	if (cmds == NULL)
		return (0);

	while (cmds[i])
	{
		path = get_path(envp, cmds[i][0]);
		if (path == NULL)
		{
			ft_printf("pipex: command not found: %s\n", cmds[i][0]);
			return (0);
		}
		i++;
	}
	return (1);
}

void free_pipex(t_pipex *pipex)
{
	int i = 0;

	while (pipex->cmds[i])
	{
		free(pipex->cmds[i]);
		i++;
	}
	free(pipex->cmds);
	free(pipex);
}
