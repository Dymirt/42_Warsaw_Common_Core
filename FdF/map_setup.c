/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:34 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/10 17:09:57 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot ***allocate_map(int map_width, int map_height)
{
	t_dot ***map;
	int i;

	map = (t_dot ***)malloc(sizeof(t_dot ***) * map_height);
	i = 0;
	while (i < map_height)
	{
		map[i] = (t_dot **)malloc(sizeof(t_dot **) * map_width);
		i++;
	}
	return (map);
}


void translate_map_3d(char	***map, t_dot ***coordinates, int map_width, int map_height)
{
	int row;
	int col = 0;
	int min_x;
	int min_y;
	char **data;

	t_dot *dot;

	while (col < map_height)
	{
		row = 0;
		while (row < map_width)
		{
			dot = (t_dot *)malloc(sizeof(t_dot));
			data = ft_split(map[col][row], ',');
			if (data[1])
				dot->color = ft_atoi_base(data[1] + 2, "0123456789ABCDEF");
			else
				dot->color = 0xFFFFFF;
			dot->x = isometric_x(row, col, 0.8);
			dot->y = isometric_y(dot->x, col, atoi(data[0]), 0.8);
			ft_free_split(data);
			coordinates[col][row] = dot;
			if (dot->x < min_x)
				min_x = dot->x;
			if (dot->y < min_y)
				min_y = dot->y;
			row++;
		}
		col++;
	}
	col = 0;
	while (col < map_height)
	{
		row = 0;
		while (row < map_width)
		{
			coordinates[col][row]->x += abs(min_x);
			coordinates[col][row]->y += abs(min_y);
			row++;
		}
		col++;
	}
}

void	load_map(char *file_name, char ****map, int *map_width, int *map_height)
{
	int		fd;
	char	*line;
	char	**map_line;

	fd = open(file_name, O_RDONLY);
	while (fd > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			*map = (char ***)ft_realloc(*map, sizeof(char **) * *map_height, sizeof(char **) * (*map_height + 1));
			(*map)[*map_height] = NULL;
			free(line);
			close(fd);
			return ;
		}
		else
		{
			map_line = ft_split(line, ' ');
			if (*map_width == 0)
				while (map_line[*map_width])
					(*map_width) += 1;
			(*map_height) += 1;
			*map = (char ***)ft_realloc(*map, sizeof(char **) * (*map_height - 1), sizeof(char **) * *map_height);
			if (*map == NULL)
			{
				ft_printf("Memory allocation failed\n");
				close(fd);
				return;
			}
			(*map)[*map_height - 1] = map_line;
		}
		free(line);
	}
	ft_printf("Errorw\n");
	return ;
}

void free_map_data (t_map *map_data)
{
	int i;
	int j;

	i = 0;
	while (i < map_data->height)
	{
		j = 0;
		while (j < map_data->width)
		{
			free(map_data->map2d[i][j]);
			free(map_data->map3d[i][j]);
			j++;
		}
		free(map_data->map2d[i]);
		free(map_data->map3d[i]);
		i++;
	}
	free(map_data->map2d);
	free(map_data->map3d);
	free(map_data);
}
