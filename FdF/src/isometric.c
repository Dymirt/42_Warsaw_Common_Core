/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:58 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/15 02:57:59 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#include <stdio.h>

void			isometric(t_map *map, t_dot *dot);

void	new_dot(t_map *map, t_dot *dot)
{
	char	**data;
	int		col;
	int		row;

	col = map->tmp->col;
	row = map->tmp->row;
	data = ft_split(map->map2d[col][row], ',');
	if (data[1] != NULL)
		dot->color = get_color(data[1]);
	else
		dot->color = 0xFFFFFF;
	dot->x = (float)row;
	dot->z = (float)ft_atoi(data[0]);
	dot->y = (float)col;
	ft_free_split(data);
}

void	isometric_view(t_map *map)
{
	for_each_t_dot(map, isometric);
	reset_min_max(map);
}

void	isometric(t_map *map, t_dot *dot)
{
	float	x;
	float	y;
	float	z;

	x = dot->x;
	y = dot->y;
	z = dot->z;
	dot->x = (float)(x - y)*cos(map->cos_angle);
	dot->y = (float)(x + y)*sin(map->sin_angle) - z;
}

void	create_3d_map(t_map *map)
{
	for_each_t_dot(map, new_dot);
}
