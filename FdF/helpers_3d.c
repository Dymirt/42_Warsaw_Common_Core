/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:58 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/12 01:06:27 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

float	isometric_x(float x, float y, float rotation)
{
	return ((float)(x - y)*cos(rotation));
}

float	isometric_y(float x, float y, float z, float rotation)
{
	return ((float)(x + y)*sin(rotation) - z);
}

void	scale_3d_map(t_map *map_data)
{
	int	col;
	int	row;

	col = 0;
	while (col < map_data->height)
	{
		row = 0;
		while (row < map_data->width)
		{
			map_data->map3d[col][row]->x *= map_data->scale;
			map_data->map3d[col][row]->y *= map_data->scale;
			row++;
		}
		col++;
	}
}
