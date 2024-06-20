/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:50:27 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 13:34:07 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nearest_value(t_int_arr *s, int value, int (*f)(int a, int b));

int	nearest_larfer_i(t_int_arr *s, int value)
{
	return (nearest_value(s, value, ft_is_larger));
}

int	nearest_smaller_i(t_int_arr *s, int value)
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

int	moves(t_int_arr *s, int value)
{
	int	moves_up;
	int	moves_down;

	moves_up = nearest_smaller_i(s, value);
	moves_down = s->size - moves_up;
	if (moves_up < moves_down)
		return (moves_up);
	else
		return (moves_down);
}

int	optimal_value_for_push(t_int_arr *a, t_int_arr *b)
{
	int	i;
	int	min_i;

	i = 0;
	min_i = 0;
	while (i < a->size)
	{
		if ((moves(b, a->array[min_i]) + min_i) >= (moves(b, a->array[i]) + i))
			min_i = i;
		i++;
	}
	return (min_i);
}
