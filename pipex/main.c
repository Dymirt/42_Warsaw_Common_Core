/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:45:16 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/24 02:23:27 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp);

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	(void)argc;
	(void)argv;
	path = get_path(envp);
	if (path == NULL)
	{
		ft_putstr_fd("PATH not found\n", 2);
		exit(1);
	}
	ft_putstr_fd(path, 1);
	return (0);
}

char	*get_path(char **envp)
{
	char	**paths;
	char	*path;

	path = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			paths = ft_split(ft_strchr(*envp, '/'), ':');
			if (paths)
			{
				path = ft_strdup(paths[0]);
				ft_free_split(paths);
			}
		}
		envp++;
	}
	return (path);
}
