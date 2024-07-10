/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:58 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/10 17:00:38 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int isometric_x (int x, int y, float rotation)
{
	return ((x - y) * cos(rotation));
}

int isometric_y (int x, int y, int z, float rotation)
{
	return ((x + y) * sin(rotation) - z);
}

void scale_3d_map(t_map *map_data)
{
	int col = 0;
	int row;
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
