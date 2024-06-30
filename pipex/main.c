/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:45:16 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/30 23:39:23 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(t_pipex *pipex);

void	execute_command(char **cmd, t_pipex *pipex)
{
	char	*path;

	path = get_path(pipex->envp_path, cmd[0]);
	if (path == NULL)
	{
		perror("path");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (execve(path, cmd, pipex->envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
}

void	pipe_exec(t_pipex *pipex)
{
	int	pipefd[2];
	int	pid;

	if (pipex->cmd_index > 0)
	{
		make_pipe(pipefd);
		pid = make_fork();
		if (pid == 0)
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[1]);
			pipex->cmd_index--;
			pipe_exec(pipex);
		}
		else
		{
			close(pipefd[1]);
			waitpid(pid, NULL, 0);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
		}
	}
	execute_command(pipex->cmds[pipex->cmd_index], pipex);
}

int	main(int argc, char **argv, char **envp)
{
	struct s_pipex	*pipex;

	if (!argc_is_valid(argc))
		exit(EXIT_FAILURE);
	pipex = malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (0);
	pipex->cmds_count = argc - 3;
	pipex->cmd_index = pipex->cmds_count - 1;
	pipex->envp = envp;
	if (!init_pipex(argc, argv, pipex))
		exit(EXIT_FAILURE);
	pipex_start(pipex);
	free_pipex(pipex);
	return (0);
}

void	pipex_start(t_pipex *pipex)
{
	int			pid;

	pid = make_fork();
	if (pid == 0)
	{
		dup2(pipex->in_fd, STDIN_FILENO);
		close(pipex->in_fd);
		dup2(pipex->out_fd, STDOUT_FILENO);
		close(pipex->out_fd);
		pipe_exec(pipex);
	}
	waitpid(pid, NULL, 0);
}
