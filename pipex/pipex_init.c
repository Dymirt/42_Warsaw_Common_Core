/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:26:55 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/30 23:40:09 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***get_commands(int argc, char **argv);
int		open_files(char *infile, char *outfile, t_pipex *pipex);
void	free_array_of_araies_of_strings(char ***array);

int	init_pipex(int argc, char **argv, t_pipex *pipex)
{
	if (!open_files(argv[1], argv[argc - 1], pipex))
		return (0);
	pipex->envp_path = envp_path(pipex->envp);
	if (pipex->envp_path == NULL)
	{
		close(pipex->in_fd);
		close(pipex->out_fd);
		free(pipex);
		return (0);
	}
	pipex->cmds = get_commands(argc, argv);
	if (pipex->cmds == NULL || !comands_is_valid(pipex->envp_path, pipex->cmds))
	{
		if (pipex->cmds == NULL)
			perror("get_commands");
		else
			free_array_of_araies_of_strings(pipex->cmds);
		ft_free_split(pipex->envp_path);
		close(pipex->in_fd);
		close(pipex->out_fd);
		free(pipex);
		return (0);
	}
	return (1);
}

char	***get_commands(int argc, char **argv)
{
	char	***cmds;
	int		i;

	i = 0;
	cmds = (char ***)malloc(sizeof(char **) * (argc - 2));
	while ((i + 2) < argc - 1)
	{
		cmds[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

int	open_files(char *infile, char *outfile, t_pipex *pipex)
{
	pipex->in_fd = open(infile, O_RDONLY);
	if (pipex->in_fd == -1)
		perror("open infile");
	pipex->out_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->out_fd == -1)
	{
		close(pipex->in_fd);
		perror("open outfile");
	}
	if (pipex->in_fd == -1 || pipex->out_fd == -1)
	{
		free(pipex);
		return (0);
	}
	return (1);
}

void	free_pipex(t_pipex *pipex)
{
	free_array_of_araies_of_strings(pipex->cmds);
	ft_free_split(pipex->envp_path);
	free(pipex);
}

void	free_array_of_araies_of_strings(char ***array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_free_split(array[i]);
		i++;
	}
	free(array);
}
