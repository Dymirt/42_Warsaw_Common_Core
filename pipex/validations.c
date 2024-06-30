/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:15:01 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/30 23:44:40 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	comands_is_valid(char **envp, char ***cmds)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
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
		free(path);
		i++;
	}
	return (1);
}

int	argc_is_valid(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd... outfile\n", 2);
		return (0);
	}
	return (1);
}
