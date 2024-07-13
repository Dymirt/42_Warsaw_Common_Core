/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:10:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/13 14:36:21 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drow_img (t_fdf *fdf);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_dot *start, t_dot *end, t_data img)
{
	int		x_steps;
	int		y_steps;
	int		max;
	float	x_step;
	float	y_step;
	float x;
	float y;

	x = (float)start->x;
	y = (float)start->y;
	x_steps = end->x - start->x;
	y_steps = end->y - start->y;
	if (abs(x_steps) > abs(y_steps))
		max = abs(x_steps);
	else
		max = abs(y_steps);
	x_step = x_steps / (float)max;
	y_step = y_steps / (float)max;
	while ((int)(x - end->x) || (int)(y - end->y))
	{
		my_mlx_pixel_put(&img, (int)x, (int)y, start->color);
		x += x_step;
		y += y_step;
	}
}

int key_hook(int keycode, void *param)
{
	t_fdf *fdf = (t_fdf *)param;
	if (keycode == ESC_KEY_MAC)
	{
		free_map_data(fdf->map_data);
		exit(0);
	}
	if (keycode == SCALE_P)
	{
		fdf->map_data->scale += 1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		drow_img(fdf);
	}
	if (keycode == SCALE_M)
	{
		fdf->map_data->scale -= 1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		drow_img(fdf);
	}
	if (keycode == SIN_P)
	{
		if (fdf->map_data->sin_angle + 0.1 < 1.5)
			fdf->map_data->sin_angle += 0.1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		drow_img(fdf);
	}
	if (keycode == SIN_M)
	{
		if (fdf->map_data->sin_angle - 0.1 > 0 )
		fdf->map_data->sin_angle -= 0.1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		drow_img(fdf);
	}
	if (keycode == 42)
	{
		fdf->map_data->cos_angle += 0.1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		drow_img(fdf);
	}
	if (keycode == 39)
	{
		if (fdf->map_data->cos_angle - 0.1 > 0 )
			fdf->map_data->cos_angle -= 0.1;
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		drow_img(fdf);
	}

	ft_printf("Keycode: %d\n", keycode);
	return (0);
}

void	drow_img(t_fdf *fdf)
{
	int	col;
	int	row;

	fdf->img.img = mlx_new_image(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length,
								&fdf->img.endian);
	fdf->map_data->map3d = allocate_map(fdf->map_data->width, fdf->map_data->height);
	translate_map_3d(fdf->map_data);
	col = 0;
	while (col < fdf->map_data->height)
	{
		row = 0;
		while (row < fdf->map_data->width)
		{
			if (row + 1 < fdf->map_data->width)
				draw_line(fdf->map_data->map3d[col][row], fdf->map_data->map3d[col][row + 1], fdf->img);
			if (col + 1 < fdf->map_data->height)
				draw_line(fdf->map_data->map3d[col][row], fdf->map_data->map3d[col + 1][row], fdf->img);
			free(fdf->map_data->map3d[col][row]);
			row++;
		}
		free(fdf->map_data->map3d[col]);
		col++;
	}
	free(fdf->map_data->map3d);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->map_data = malloc(sizeof(t_map));
	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	load_map(argv[1], &fdf->map_data->map2d, &fdf->map_data->width, &fdf->map_data->height);
	if (fdf->map_data->map2d == NULL)
	{
		ft_printf("Load map Error\n");
		return (1);
	}
	fdf->mlx_win = mlx_new_window(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Hello world!");
	fdf->map_data->scale = 20;
	fdf->map_data->sin_angle = 0.8;
	fdf->map_data->cos_angle = -0.8;
	drow_img(fdf);
	mlx_key_hook(fdf->mlx_win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}
