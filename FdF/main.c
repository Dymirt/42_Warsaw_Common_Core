/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:10:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/10 17:05:55 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/*
void draw_line(int x1, int y1, int x2, int y2, t_data img , char ***map, int scale)
{
	float x_step;
	float y_step;
	float x;
	float y;
	int max;
	int z1;
	int z2;
	z1 = ft_atoi(map[(int)y1][(int)x1]);
	z2 = ft_atoi(map[(int)y2][(int)x2]);
	x1 *= scale;
	y1 *= scale;
	z1 *= scale;
	x1 = isometric_x(x1, y1);
	y1 = isometric_y(x1, y1, z1);
	ft_printf("x1: %d y1:%d\n", x1, y1);
	x = (float)x1;
	y = (float)y1;
	x2 = isometric_x(x2, y2);
	y2 = isometric_y(x2, y2, z2);
	x2 *= scale;
	y2 *= scale;
	z2 *= scale;
	ft_printf("x2: %d y2:%d\n line \n", x2, y2);
	x_step = abs((int)x2 - (int)x1);
	y_step = abs((int)y2 - (int)y1);
	if (x_step > y_step)
		max = x_step;
	else
		max = y_step;
	x_step /= max;
	y_step /= max;
	my_mlx_pixel_put(&img, (int)x, (int)y, 0xFFFFFF);
	return ;
	while ((int)x - x2 || (int)y - y2)
	{

		my_mlx_pixel_put(&img, (int)x, (int)y, 0xFFFFFF);
		x += x_step;
		y += y_step;
	}
}
*/
#define ESC_KEY_MAC 53

int key_hook(int keycode, void *param)
{
	t_map *map_data = (t_map *)param;
	if (keycode == ESC_KEY_MAC)
	{
		free_map_data(map_data);
		exit(0);
	}

	return (0);
}



int main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	*map_data;

	map_data = malloc(sizeof(t_map));

	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	map_data->map2d = NULL;
	load_map(argv[1], &map_data->map2d, &map_data->width, &map_data->height);
	if (map_data->map2d == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}

	int scale_y = SCREEN_HEIGHT / map_data->height;
	int scale_x = SCREEN_HEIGHT / map_data->width;
	int scale = scale_x < scale_y ? scale_x : scale_y;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_data->width * scale + scale + 100, map_data->height * scale + scale + 100, "Hello world!");
	img.img = mlx_new_image(mlx, map_data->width * scale + scale + 50, map_data->width * scale + scale + 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	map_data->map3d = allocate_map(map_data->width, map_data->height);
	translate_map_3d(map_data->map2d, map_data->map3d, map_data->width, map_data->height);
	map_data->scale = scale;
	scale_3d_map(map_data);
	int col = 0;
	int row;
	while (col < map_data->height)
	{
		row = 0;
		while (row < map_data->width)
		{
			int x = map_data->map3d[col][row]->x;
			int y = map_data->map3d[col][row]->y;
			my_mlx_pixel_put(&img, x, y, map_data->map3d[col][row]->color);
			row++;
		}
		col++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, map_data);
	mlx_loop(mlx);
}
