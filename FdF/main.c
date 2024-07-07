/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:10:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/07 22:27:58 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void	load_map(char *file_name, char ****map, int *map_width, int *map_height)
{
	int		fd;
	char	*line;
	char	**map_line;

	fd = open(file_name, O_RDONLY);
	while (fd > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			*map = (char ***)ft_realloc(*map, sizeof(char **) * *map_height, sizeof(char **) * (*map_height + 1));
			(*map)[*map_height] = NULL;
			free(line);
			close(fd);
			return ;
		}
		else
		{
			map_line = ft_split(line, ' ');
			if (*map_width == 0)
				while (map_line[*map_width])
					(*map_width) += 1;
			(*map_height) += 1;
			*map = (char ***)ft_realloc(*map, sizeof(char **) * (*map_height - 1), sizeof(char **) * *map_height);
			if (*map == NULL)
			{
				ft_printf("Memory allocation failed\n");
				close(fd);
				return;
			}
			(*map)[*map_height - 1] = map_line;
		}
		free(line);
	}
	ft_printf("Errorw\n");
	return ;
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	***map;
	int		map_width = 0;
	int		map_height = 0;

	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	map = NULL;
	load_map(argv[1], &map, &map_width, &map_height);
	if (map == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	int scale_y = 720 / map_height;
	int scale_x = 720 / map_width;
	int scale = scale_x < scale_y ? scale_x : scale_y;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map_width * scale + scale + 100, map_height * scale + scale + 100, "Hello world!");
	img.img = mlx_new_image(mlx, map_width * scale + scale + 50, map_width * scale + scale + 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int i = 0;
	int j = 0;
	while	(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			my_mlx_pixel_put(&img, (j * scale) + scale + 50, (i * scale) + scale + 50, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
