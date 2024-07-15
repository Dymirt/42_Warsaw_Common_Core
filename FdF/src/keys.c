/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:38:36 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/16 01:56:54 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	move_keys(t_map *map, int keycode);
static int	scale_keys(t_map *map, int keycode);
static int	sin_keys(t_map *map, int keycode);
static int	cos_keys(t_map *map, int keycode);

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (move_keys(fdf->map_data, keycode)
		|| scale_keys(fdf->map_data, keycode)
		|| sin_keys(fdf->map_data, keycode)
		|| cos_keys(fdf->map_data, keycode))
	{
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
		return (0);
	}
	if (keycode == ESC_KEY_MAC)
	{
		free_map_data(fdf->map_data);
		exit(0);
	}
	ft_printf("Keycode: %d\n", keycode);
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
		map->scale *= 1.1;
	else if (keycode == SCALE_DOWN)
		map->scale *= 0.9;
	else
		return (0);
	return (1);
}

static int	sin_keys(t_map *map, int keycode)
{
	if (keycode == SIN_P)
		map->sin_angle += 0.1;
	else if (keycode == SIN_M)
		map->sin_angle -= 0.1;
	else
		return (0);
	return (1);
}

static int	cos_keys(t_map *map, int keycode)
{
	if (keycode == COS_P)
		map->cos_angle += 0.1;
	else if (keycode == COS_M)
		map->cos_angle -= 0.1;
	else
		return (0);
	return (1);
}
