/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_int_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:32:49 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 01:34:49 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	edge_value(t_int_arr *s, int (*f)(int a, int b));

int	get_index(t_int_arr *s, int value)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (s->array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	min_value(t_int_arr *stack)
{
	return (edge_value(stack, ft_is_smaller));
}

int	max_value(t_int_arr *stack)
{
	return (edge_value(stack, ft_is_larger));
}

int	edge_value(t_int_arr *s, int (*f)(int a, int b))
{
	int	i;
	int	edge;

	i = 1;
	edge = s->array[0];
	while (i < s->size)
	{
		if (f(s->array[i], edge))
			edge = s->array[i];
		i++;
	}
	return (edge);
}
