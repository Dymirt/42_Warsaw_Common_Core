/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:10:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/15 02:59:52 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	mlx_setup(t_fdf *fdf);
void	fdf_setup(t_fdf *fdf);
void	check_inpit(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	check_inpit(argc, argv);
	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(1);
	}
	fdf_setup(fdf);
	read_map_file(fdf, argv[1]);
	mlx_setup(fdf);
	drow_img(fdf);
	mlx_key_hook(fdf->mlx_win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}

void	fdf_setup(t_fdf *fdf)
{
	fdf->map_data = malloc(sizeof(t_map));
	if (fdf->map_data == NULL)
	{
		ft_printf("Memory allocation failed\n");
		free(fdf);
		exit(1);
	}
	fdf->map_data->scale = 20.0;
	fdf->map_data->sin_angle = 0.523599;
	fdf->map_data->cos_angle = 0.523599;
	fdf->map_data->degrees_rotate = 4.0;
	fdf->map_data->moves_x = 0.0;
	fdf->map_data->moves_y = 0.0;
	fdf->map_data->on_start = 1;
}

void	mlx_setup(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FdF");
}

void	check_inpit(int argc, char **argv)
{
	if (argc != 2
		|| ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".fdf", 4) != 0)
	{
		ft_printf("Usage: %s <filename>.fdf\n", argv[0]);
		exit(1);
	}
}

void	free_map_data(t_map *map_data)
{
	int	col;
	int	row;

	col = 0;
	while (col < map_data->height)
	{
		row = 0;
		while (row < map_data->width)
		{
			free(map_data->map2d[col][row]);
			row++;
		}
		free(map_data->map2d[col]);
		col++;
	}
	free(map_data->map2d);
	free(map_data);
}
