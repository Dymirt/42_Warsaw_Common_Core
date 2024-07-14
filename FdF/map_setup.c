/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:34 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 20:58:13 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_map(char *file_name, char ****map, int *width, int *height)
{
	int		fd;
	char	*line;
	char	**map_line;

	fd = open(file_name, O_RDONLY);
	ft_printf("File descriptor: %d\n", fd);
	while (fd > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			*map = (char ***)ft_realloc(*map, sizeof(char **) * (*height),
					sizeof(char **) * (*height + 1));
			(*map)[*height] = NULL;
			free(line);
			close(fd);
			return ;
		}
		else
		{
			map_line = ft_split(line, ' ');
			if (*width == 0)
				while (map_line[*width])
					(*width) += 1;
			(*height) += 1;
			*map = (char ***)ft_realloc(*map, sizeof(char **) * (*height - 1),
					sizeof(char **) * *height);
			if (*map == NULL)
			{
				ft_printf("Memory allocation failed\n");
				close(fd);
				return ;
			}
			(*map)[*height - 1] = map_line;
		}
		free(line);
	}
}

void	free_map_data(t_map *map_data)
{
	int	col;
	int	row;

	col = 0;
	while (col < map_data->height)
	{
		row = 0;
		while (row < map_data->width)
		{
			free(map_data->map2d[col][row]);
			row++;
		}
		free(map_data->map2d[col]);
		col++;
	}
	free(map_data->map2d);
	free(map_data);
}


