/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:40:43 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 17:52:21 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	crop_scale(t_map *map);

void	apply_moves(t_map *map)
{
	for_each_t_dot(map, move_dot);
	update_map_min_max(map);
}

void	scale_3d_map(t_map *map)
{
	if (map->on_start == 1)
	{
		crop_scale(map);
		map->on_start = 0;
	}
	for_each_t_dot(map, scale_dot);
	update_map_min_max(map);
}

static void	crop_scale(t_map *map)
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
