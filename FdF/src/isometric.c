/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:58 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 23:10:05 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static float	isometric_x(float x, float y, float rotation);
static float	isometric_y(float x, float y, float z, float rotation);

void	new_dot(t_map *map, t_dot *dot)
{
	char	**data;
	int		col;
	int		row;

	col = map->tmp->col;
	row = map->tmp->row;
	data = ft_split(map->map2d[col][row], ',');
	if (data[1] != NULL)
		dot->color = get_color(data[1]);
	else
		dot->color = 0xFFFFFF;
	dot->x = isometric_x(row, col, map->cos_angle);
	dot->y = isometric_y(dot->x, col, (float)ft_atoi(data[0]), map->sin_angle);
	ft_free_split(data);
}

void	create_3d_map(t_map *map)
{
	for_each_t_dot(map, new_dot);
	reset_min_max(map);
}

static float	isometric_x(float x, float y, float rotation)
{
	return ((float)(x - y)*cos(rotation));
}

static float	isometric_y(float x, float y, float z, float rotation)
{
	return ((float)(x + y)*sin(rotation) - z);
}
