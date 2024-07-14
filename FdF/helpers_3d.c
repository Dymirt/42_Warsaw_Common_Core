/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:58 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 15:48:03 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

#define PI 3.14159265358979323846

void	transate_to_positive(t_map *map);
void	update_map_min_max(t_map *map);
void	center_map_to_screen(t_map *map);
t_dot	*get_center(t_map *map);
void	crop_scale(t_map *map);

void	scale_3d_map(t_map *map)
{
	int	col;
	int	row;

	if (map->on_start == 1)
	{
		crop_scale(map);
		map->on_start = 0;
	}
	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			map->map3d[col][row]->x *= map->scale;
			map->map3d[col][row]->y *= map->scale;
			row++;
		}
		col++;
	}
	update_map_min_max(map);
}

void	transate_to_positive(t_map *map)
{
	int		row;
	int		col;

	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			map->map3d[col][row]->x += fabs(map->min_x);
			map->map3d[col][row]->y += fabs(map->min_y);
			row++;
		}
		col++;
	}
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

void	rotare_map_around(t_map *map, float degrees)
{
	int	col;
	int	row;

	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			rotate_point_around(map->map3d[col][row], degrees, map);
			row++;
		}
		col++;
	}
	update_map_min_max(map);
}

void	rotate_map(t_map *map)
{
	int	col;
	int	row;

	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			rotate_point(map->map3d[col][row], map->degrees_rotate);
			row++;
		}
		col++;
	}
	update_map_min_max(map);
}

void	rotate_point_around(t_dot *dot, float degrees, t_map *map)
{
	t_dot	*center;

	center = get_center(map);
	dot->x -= center->x;
	dot->y -= center->y;
	rotate_point(dot, degrees);
	dot->x += center->x;
	dot->y += center->y;
}

t_dot	*get_center(t_map *map)
{
	t_dot	*center;

	center = (t_dot *)malloc(sizeof(t_dot));
	center->x = (map->max_x - map->min_x) / 2;
	center->y = (map->max_y - map->min_y) / 2;
	return (center);
}

void	rotate_point(t_dot *dot, float degrees)
{
	float	radians;
	float	cos_theta;
	float	sin_theta;

	radians = degrees * (PI / 180.0);
	cos_theta = cos(radians);
	sin_theta = sin(radians);
	dot->x = dot->x * cos_theta + dot->y * sin_theta;
	dot->y = -dot->x * sin_theta + dot->y * cos_theta;
}

void	crop_scale(t_map *map)
{
	while (map->max_x * map->scale > SCREEN_WIDTH
		|| map->max_y * map->scale > SCREEN_HEIGHT)
	{
		map->scale -= 0.1;
	}
	while (map->min_x * map->scale < 0 || map->min_y * map->scale < 0)
	{
		map->scale -= 0.1;
	}
}

void	apply_moves(t_map *map)
{
	int	col;
	int	row;

	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			map->map3d[col][row]->x += map->moves_x;
			map->map3d[col][row]->y += map->moves_y;
			row++;
		}
		col++;
	}
}
