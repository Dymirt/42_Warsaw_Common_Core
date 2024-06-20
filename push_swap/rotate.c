/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:07:53 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/20 01:57:00 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_int_arr *stack, char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->array[0];
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = tmp;
	if (*str)
		ft_putendl_fd(str, 1);
}

void	rr(t_int_arr *stack_a, t_int_arr *stack_b)
{
	rotate(stack_a, "");
	rotate(stack_b, "");
	ft_putendl_fd("rr", 1);
}

int	check_for_rotate(t_int_arr *stack)
{
	return (stack->array[0] > stack->array[stack->size - 1]);
}

void	sort_rotate(t_int_arr *s)
{
	int	min_v;
	int	min_i;

	min_v = min_value(s);
	while (!ft_sorted(s->array, s->size))
	{
		min_i = get_index(s, min_v);
		if (min_i < (s->size - min_i))
			rotate(s, "ra");
		else
			reverse_rotate(s, "rra");
	}
}
