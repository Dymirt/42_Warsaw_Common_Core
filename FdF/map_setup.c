/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:34 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 19:13:03 by dkolida          ###   ########.fr       */
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

t_dot	***malloc_3d_fdf_map(int map_width, int map_height)
{
	t_dot	***map;
	int		col;
	int		row;

	map = (t_dot ***)malloc(sizeof(t_dot ***) * map_height);
	col = 0;
	while (col < map_height)
	{
		map[col] = (t_dot **)malloc(sizeof(t_dot **) * map_width);
		row = 0;
		while (row < map_width)
		{
			map[col][row] = (t_dot *)malloc(sizeof(t_dot));
			row++;
		}
		col++;
	}
	return (map);
}

void	free_map_data(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			free(map_data->map2d[i][j]);
			j++;
		}
		free(map_data->map2d[i]);
		i++;
	}
	free(map_data->map2d);
	free(map_data);
}
