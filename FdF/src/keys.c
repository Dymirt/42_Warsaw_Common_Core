/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:38:36 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/16 14:58:44 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	move_keys(t_map *map, int keycode);
static int	scale_keys(t_map *map, int keycode);
//static int	sin_keys(t_map *map, int keycode);

int	close_window_hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	free_map_data(fdf->map_data);
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (scale_keys(fdf->map_data, keycode))
	{
		object_zoom(fdf);
		return (0);
	}
	if (move_keys(fdf->map_data, keycode))
	{
		move_view_point(fdf);
		return (0);
	}
	if (keycode == ESC_KEY_MAC)
	{
		free_map_data(fdf->map_data);
		exit(0);
	}
	return (0);
}

static int	move_keys(t_map *map, int keycode)
{
	if (keycode == MOVE_UP)
		map->moves_y += 10;
	else if (keycode == MOVE_DOWN)
		map->moves_y -= 10;
	else if (keycode == MOVE_LEFT)
		map->moves_x += 10;
	else if (keycode == MOVE_RIGHT)
		map->moves_x -= 10;
	else
		return (0);
	return (1);
}

static int	scale_keys(t_map *map, int keycode)
{
	if (keycode == SCALE_UP)
		map->scale = 1.1;
	else if (keycode == SCALE_DOWN)
		map->scale = 0.9;
	else
		return (0);
	return (1);
}
