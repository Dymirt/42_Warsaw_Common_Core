/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:58 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 15:35:32 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static float	isometric_x(float x, float y, float rotation);
static float	isometric_y(float x, float y, float z, float rotation);

void	translate_map_3d(t_map *map)
{
	int		row;
	int		col;
	char	**data;
	t_dot	*dot;

	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			dot = (t_dot *)malloc(sizeof(t_dot));
			data = ft_split(map->map2d[col][row], ',');
			if (data[1] != NULL)
				dot->color = get_color(data[1]);
			else
				dot->color = 0xFFFFFF;
			dot->x = isometric_x(row, col, map->cos_angle);
			dot->y = isometric_y(dot->x, col, (float)ft_atoi(data[0]), map->sin_angle);
			ft_free_split(data);
			map->map3d[col][row] = dot;
			row++;
		}
		col++;
	}
	update_map_min_max(map);
}

static float	isometric_x(float x, float y, float rotation)
{
	return ((float)(x - y)*cos(rotation));
}

static float	isometric_y(float x, float y, float z, float rotation)
{
	return ((float)(x + y)*sin(rotation) - z);
}
