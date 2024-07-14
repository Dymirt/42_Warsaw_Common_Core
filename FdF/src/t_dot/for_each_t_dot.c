/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_each_t_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:27:18 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 20:25:13 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	for_each_t_dot(t_map *map, void (*f)(t_map *, t_dot *))
{
	int	col;
	int	row;

	col = 0;
	map->tmp = (t_tmp *)malloc(sizeof(t_tmp));
	while (col < map->height)
	{
		row = 0;
		while (row < map->width)
		{
			map->tmp->col = col;
			map->tmp->row = row;
			f(map, map->map3d[col][row]);
			row++;
		}
		col++;
	}
	free(map->tmp);
}
