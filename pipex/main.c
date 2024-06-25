/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:45:16 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/26 01:35:48 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp);

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int pid;


	(void)argc;
	(void)argv;

	path = get_path(envp);
	if (path == NULL)
	{
		ft_putstr_fd("PATH not found\n", 2);
		exit(1);
	}
	ft_putendl_fd(path, 2);
	pid = fork();
	if (pid == 0)
	{
		path = ft_strjoin(path, "/");
		ft_putendl_fd(path, 2);

		path = ft_strjoin(path, ft_split(argv[2], ' ')[0]);
		ft_putendl_fd(path, 2);
		//execve(cmd, ft_split(argv[2], ' '), envp);
		ft_putnbr_fd(access(path, 0), 2);
		ft_putnbr_fd(execve(path, ft_split(argv[2], ' '), envp), 2);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}

	return (0);
}

char	*get_path(char **envp)
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
				tmp = ft_strjoin(*paths, "/ls");
				if (access(tmp, X_OK) == 0)
				{
					path = *paths;
					free(tmp);
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
