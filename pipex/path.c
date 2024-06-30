/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:43:10 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/30 20:31:51 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path(char *path, char *cmd);

// This function is used to get the path of the command.
// It takes the environment variables and the command as arguments.
// It returns the path of the command.
// If the command is not found, it returns NULL.
// If the command is found, but the path is not executable, it returns NULL.
// If the command is found, it returns the path of the command.
char	**envp_path(char **envp)
{
	char	**path;

	path = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			path = ft_split(ft_strchr(*envp, '/'), ':');
			break ;
		}
		envp++;
	}
	return (path);
}

char	*get_path(char **envp_paths, char *cmd)
{
	char	*path;

	path = NULL;
	while (*envp_paths)
	{
		path = join_path(*envp_paths, cmd);
		if (path != NULL && access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
		envp_paths++;
	}
	return (path);
}

// This function is used to join the path and the command.
// It takes the path and the command as arguments.
// It returns the joined path and command.
// If the path is NULL, it returns NULL.
// If the command is NULL, it returns NULL.
static char	*join_path(char *path, char *cmd)
{
	char	*joined;
	char	*tmp;

	if (path == NULL || cmd == NULL)
		return (NULL);
	tmp = ft_strjoin(path, "/");
	if (tmp == NULL)
		return (NULL);
	joined = ft_strjoin(tmp, cmd);
	if (joined == NULL)
		return (NULL);
	free(tmp);
	return (joined);
}
