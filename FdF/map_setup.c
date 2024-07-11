/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:34 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/12 01:38:27 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_dot	***allocate_map(int map_width, int map_height)
{
	t_dot	***map;
	int		i;

	map = (t_dot ***)malloc(sizeof(t_dot ***) * map_height);
	i = 0;
	while (i < map_height)
	{
		map[i] = (t_dot **)malloc(sizeof(t_dot **) * map_width);
		i++;
	}
	return (map);
}

void translate_map_3d(t_map *map)
{
	int		row;
	int		col;
	float	min_x = 0;
	float	min_y = 0;
	float	max_x = 0;
	float	max_y = 0;
	char	**data;

	t_dot *dot;
	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			dot = (t_dot *)malloc(sizeof(t_dot));
			data = ft_split(map->map2d[col][row], ',');
			if (data[1] != NULL)
			{
				char *g;
				char *b;
				char *r = ft_substr(data[1], 2, 2);
				// TODO lovercase clors
				printf("Color: %i\n", ft_atoi_base(r, "0123456789ABCDEF"));

				if (ft_strlen(data[1]) > 4)
					g = ft_substr(data[1], 4, 2);
				else
					g = ft_substr("00", 0, 2);
				if (ft_strlen(data[1]) > 6)
					b = ft_substr(data[1], 6, 2);
				else
					b = ft_substr("00", 0, 2);
				dot->color = create_trgb(ft_atoi_base("00", "0123456789ABCDEF"), ft_atoi_base(r, "0123456789ABCDEF"), ft_atoi_base(g, "0123456789ABCDEF"), ft_atoi_base(b, "0123456789ABCDEF"));
				free(r);
				free(g);
				free(b);
			}
			else
				dot->color = 0x00FFFFFF;
			dot->x = isometric_x(row, col, map->cos_angle);
			dot->y = isometric_y(dot->x, col, (float)atoi(data[0]), map->sin_angle);
			ft_free_split(data);
			map->map3d[col][row] = dot;
			if (dot->x < min_x)
				min_x = dot->x;
			if (dot->y < min_y)
				min_y = dot->y;
			if (dot->x > max_x)
				max_x = dot->x;
			if (dot->y > max_y)
				max_y = dot->y;
			row++;
		}
		col++;
	}
	while ((SCREEN_WIDTH - (max_x + fabs(min_x))  * map->scale) / 2 < 0)
		map->scale -= 1;
	max_x = (SCREEN_WIDTH - (max_x + fabs(min_x)) * map->scale) / 2;
	while ((SCREEN_HEIGHT - (max_y + fabs(min_y)) * map->scale) / 2 < 0)
		map->scale -= 1;
	max_y = (SCREEN_HEIGHT - (max_y + fabs(min_y)) * map->scale) / 2;
	if (map->scale < 1)
		map->scale = 1;
	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			map->map3d[col][row]->x += fabs(min_x);
			map->map3d[col][row]->y += fabs(min_y);
			row++;
		}
		col++;
	}
	scale_3d_map(map);
	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			map->map3d[col][row]->x += max_x;
			map->map3d[col][row]->y += max_y;
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
			j++;
		}
		free(map_data->map2d[i]);
		i++;
	}
	free(map_data->map2d);
	free(map_data);
}
