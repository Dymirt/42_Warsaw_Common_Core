/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:58 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 20:41:08 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	update_map_min_max(t_map *map);
void	center_map_to_screen(t_map *map);
void	crop_scale(t_map *map);

void	transate_to_positive(t_map *map)
{
	for_each_t_dot(map, to_positive);
	update_map_min_max(map);
}

void	update_map_min_max(t_map *map)
{
	int		row;
	int		col;

	map->min_x = 0;
	map->min_y = 0;
	map->max_x = 0;
	map->max_y = 0;
	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			if (map->map3d[col][row]->x < map->min_x)
				map->min_x = map->map3d[col][row]->x;
			if (map->map3d[col][row]->y < map->min_y)
				map->min_y = map->map3d[col][row]->y;
			if (map->map3d[col][row]->x > map->max_x)
				map->max_x = map->map3d[col][row]->x;
			if (map->map3d[col][row]->y > map->max_y)
				map->max_y = map->map3d[col][row]->y;
			row++;
		}
		col++;
	}
}

void	center_map_to_screen(t_map *map)
{
	int		row;
	int		col;
	float	margin_top;
	float	margin_left;

	margin_left = (SCREEN_WIDTH - map->max_x) / 2;
	margin_top = (SCREEN_HEIGHT - map->max_y) / 2;
	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			map->map3d[col][row]->x += margin_left;
			map->map3d[col][row]->y += margin_top;
			row++;
		}
		col++;
	}
	update_map_min_max(map);
}

void	rotate_map(t_map *map)
{
	for_each_t_dot(map, rotate_point);
	update_map_min_max(map);
}
