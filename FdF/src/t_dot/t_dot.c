/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:20:01 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 20:56:26 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_dot	***t_dot_allocate_2d_arr(int map_width, int map_height)
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

void t_dot_free_2d_arr(t_map *map)
{
	int col;
	int row;

	col = 0;
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			free(map->map3d[col][row]);
			row++;
		}
		free(map->map3d[col]);
		col++;
	}
	free(map->map3d);
}
