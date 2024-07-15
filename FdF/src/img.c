/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:11:52 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/15 23:56:57 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line(t_dot *start, t_dot *end, t_data img);
void	put_pixel(t_data *data, int x, int y, int color);

void	drow_img(t_fdf *fdf)
{
	fdf->map_data->img.img = mlx_new_image(fdf->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	fdf->map_data->img.addr = mlx_get_data_addr(
			fdf->map_data->img.img, &fdf->map_data->img.bits_per_pixel,
			&fdf->map_data->img.line_length, &fdf->map_data->img.endian);
	fdf->map_data->map3d = t_dot_allocate_2d_arr(fdf->map_data->width,
			fdf->map_data->height);
	ft_printf("fdf->map_data->width = %d\n", fdf->map_data->width);
	create_3d_map(fdf->map_data);
	isometric_view(fdf->map_data);
	rotate_map(fdf->map_data);
	transate_to_positive(fdf->map_data);
	scale_3d_map(fdf->map_data);
	center_map_to_screen(fdf->map_data);
	apply_moves(fdf->map_data);
	for_each_t_dot(fdf->map_data, draw_lines);
	t_dot_free_2d_arr(fdf->map_data);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win,
		fdf->map_data->img.img, 0, 0);

}

void	draw_line(t_dot *start, t_dot *end, t_data img)
{
	int		max;
	float	x_step;
	float	y_step;
	float	x;
	float	y;
	int		t_step;

	int start_color_r = start->color->r;
	int start_color_g = start->color->g;
	int start_color_b = start->color->b;
	int step_r;
	int step_g;
	int step_b;


	x = start->x;
	y = start->y;
	x_step = end->x - start->x;
	y_step = end->y - start->y;
	max = fmax(fabs(x_step), fabs(y_step));
	x_step = x_step / (float)max;
	y_step = y_step / (float)max;

	step_r= (end->color->r - start_color_r) / max;
	step_g = (end->color->g - start_color_g) / max;
	step_b = (end->color->b - start_color_b) / max;

	while (((int)(x - end->x) || (int)(y - end->y)))
	{
		if (((int)x >= 0 && (int)y >= 0
				&& (int)x < SCREEN_WIDTH && (int)y < SCREEN_HEIGHT))
			put_pixel(&img, (int)x, (int)y, create_trgb(0, start_color_r, start_color_g, start_color_b));
		x += x_step;
		y += y_step;
		start_color_r += step_r;
		start_color_g += step_g;
		start_color_b += step_b;
	}
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
