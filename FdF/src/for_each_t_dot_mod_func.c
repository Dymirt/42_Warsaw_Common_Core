/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_t_dot_mod_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:38:25 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 19:59:23 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	to_positive(t_map *map, t_dot *dot)
{
	dot->x += fabs(map->min_x);
	dot->y += fabs(map->min_y);
}

void	scale_dot(t_map *map, t_dot *dot)
{
	dot->x *= map->scale;
	dot->y *= map->scale;
}

void	move_dot(t_map *map, t_dot *dot)
{
	dot->x += map->moves_x;
	dot->y += map->moves_y;
}

void	draw_lines(t_map *map, t_dot *dot)
{
	int	col;
	int	row;

	col = map->tmp->col;
	row = map->tmp->row;
	if (row + 1 < map->width)
		draw_line(dot, map->map3d[col][row + 1], map->img);
	if (col + 1 < map->height)
		draw_line(dot, map->map3d[col + 1][row], map->img);
}
