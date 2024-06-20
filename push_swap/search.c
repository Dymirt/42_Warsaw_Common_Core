/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:50:27 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 01:57:47 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nearest_value(t_int_arr *s, int value, int (*f)(int a, int b));

int	nearest_larfer_v(t_int_arr *s, int value)
{
	return (nearest_value(s, value, ft_is_larger));
}

int	nearest_smaller_v(t_int_arr *s, int value)
{
	return (nearest_value(s, value, ft_is_smaller));
}

int	nearest_value(t_int_arr *s, int value, int (*f)(int a, int b))
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (i < s->size)
	{
		if (f(s->array[i], value))
		{
			if (!f(s->array[i], s->array[index]) || index == -1)
				index = i;
		}
		i++;
	}
	return (index);
}
