/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:10:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 20:59:51 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == ESC_KEY_MAC)
	{
		free_map_data(fdf->map_data);
		exit(0);
	}
	if (keycode == SCALE_P)
	{
		fdf->map_data->scale *= 1.1;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == SCALE_M)
	{
		fdf->map_data->scale *= 0.9;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == SIN_P)
	{
		if (fdf->map_data->sin_angle + 0.1 < 1.5)
			fdf->map_data->sin_angle += 0.1;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == SIN_M)
	{
		if (fdf->map_data->sin_angle - 0.1 > 0)
			fdf->map_data->sin_angle -= 0.1;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == 42)
	{
		fdf->map_data->degrees_rotate += 1.0;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == 39)
	{
		fdf->map_data->degrees_rotate -= 1.0;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == 126)
	{
		fdf->map_data->moves_y -= 10.0;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == 125)
	{
		fdf->map_data->moves_y += 10.0;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == 123)
	{
		fdf->map_data->moves_x -= 10.0;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	if (keycode == 124)
	{
		fdf->map_data->moves_x += 10.0;
		mlx_destroy_image(fdf->mlx, fdf->map_data->img.img);
		drow_img(fdf);
	}
	ft_printf("Keycode: %d\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
	{
		ft_printf("Memory allocation failed\n");
		return (1);
	}
	fdf->mlx = mlx_init();
	fdf->map_data = malloc(sizeof(t_map));
	if (fdf->map_data == NULL)
	{
		ft_printf("Memory allocation failed\n");
		return (1);
	}

	load_map(argv[1], &fdf->map_data->map2d, &fdf->map_data->width, &fdf->map_data->height); // Rewrite arguments
	if (fdf->map_data->map2d == NULL)
	{
		ft_printf("Load map Error\n");
		return (1);
	}
	fdf->mlx_win = mlx_new_window(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FdF");
	fdf->map_data->scale = 20.0;
	fdf->map_data->sin_angle = 0.523599;
	fdf->map_data->cos_angle = 0.523599;
	fdf->map_data->degrees_rotate = 4.0;
	fdf->map_data->moves_x = 0.0;
	fdf->map_data->moves_y = 0.0;
	fdf->map_data->on_start = 1;
	drow_img(fdf);
	mlx_key_hook(fdf->mlx_win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}
