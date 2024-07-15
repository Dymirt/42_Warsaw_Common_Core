/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:38:36 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/15 02:56:26 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	move_keys(t_map *map, int keycode);
static void	scale_keys(t_map *map, int keycode);

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	move_keys(fdf->map_data, keycode);
	scale_keys(fdf->map_data, keycode);
	if (keycode == ESC_KEY_MAC)
	{
		free_map_data(fdf->map_data);
		exit(0);
	}
	if (keycode == SIN_P)
	{
		if (fdf->map_data->sin_angle + 0.1 < 1.5)
			fdf->map_data->sin_angle += 0.1;
	}
	if (keycode == SIN_M)
	{
		if (fdf->map_data->sin_angle - 0.1 > 0)
			fdf->map_data->sin_angle -= 0.1;
	}
	mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
	drow_img(fdf);
	ft_printf("Keycode: %d\n", keycode);
	return (0);
}

static void	move_keys(t_map *map, int keycode)
{
	if (keycode == MOVE_UP)
		map->moves_y -= 10;
	if (keycode == MOVE_DOWN)
		map->moves_y += 10;
	if (keycode == MOVE_LEFT)
		map->moves_x -= 10;
	if (keycode == MOVE_RIGHT)
		map->moves_x += 10;
}

static void	scale_keys(t_map *map, int keycode)
{
	if (keycode == SCALE_UP)
		map->scale *= 1.1;
	if (keycode == SCALE_DOWN)
		map->scale *= 0.9;
}
