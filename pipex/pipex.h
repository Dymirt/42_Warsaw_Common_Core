/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:11 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/30 23:35:47 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	*path;
	int		in_fd;
	int		out_fd;
	char	***cmds;
	int		cmds_count;
	int		cmd_index;
	char	**envp;
	char	**envp_path;
}	t_pipex;

int		init_pipex(int argc, char **argv, t_pipex *pipex);
int		comands_is_valid(char **envp, char ***cmds);
char	*get_path(char **envp_paths, char *cmd);
int		argc_is_valid(int argc);
void	free_pipex(t_pipex *pipex);
char	**envp_path(char **envp);

// helpers.c
void	make_pipe(int *pipefd);
int		make_fork(void);

#endif
