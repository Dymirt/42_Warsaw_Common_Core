/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:50:27 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 17:37:48 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nearest_value(t_int_arr *s, int value, int (*f)(int a, int b));
int	calculate_moves(t_int_arr *a, t_int_arr *b, int i);

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
	return (s->array[index]);
}

int	moves_to_top(t_int_arr *s, int index)
{
	int	index_rev;

	index_rev = s->size - index;
	if (index < index_rev)
		return (index);
	else
		return (index_rev * -1);
}

int	calculate_moves(t_int_arr *a, t_int_arr *b, int i)
{
	int	moves_total;
	int	moves_a;
	int	moves_b;

	moves_a = moves_to_top(a, i);
	moves_b = moves_to_top(b, get_index(b, nearest_smaller_i(b, a->array[i])));
	if (moves_a > 0 && moves_b > 0)
		moves_total = ft_largest(moves_a, moves_b);
	else if (moves_a < 0 && moves_b < 0)
		moves_total = ft_smallest(moves_a, moves_b) * -1;
	else
	{
		if (moves_a < 0)
			moves_a *= -1;
		if (moves_b < 0)
			moves_b *= -1;
		moves_total = moves_a + moves_b;
	}
	return (moves_total);
}
