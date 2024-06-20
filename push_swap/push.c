/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:03:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/20 14:04:02 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_int_arr *stack_a, t_int_arr *stack_b, char *str)
{
	int	i;

	i = stack_b->size;
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = stack_a->array[0];
	stack_b->size ++;
	stack_a->size --;
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	ft_putendl_fd(str, 1);
}

void	push_to_b(t_int_arr *stack_a, t_int_arr *stack_b)
{
	int	i_optimal;
	int	min_v;
	int	nearest;

	min_v = min_value(stack_b);
	i_optimal = optimal_value_for_push(stack_a, stack_b);
	if (i_optimal != 0)
	{
		rotate_to(stack_a, stack_a->array[i_optimal], "ra", "rra");
	}
	else if (stack_a->array[0] > min_v)
	{
		nearest = nearest_smaller_i(stack_b, stack_a->array[0]);
		rotate_to(stack_b, stack_b->array[nearest], "rb", "rrb");
		push(stack_a, stack_b, "pb");
	}
	else
	{
		rotate_to(stack_b, max_value(stack_b), "rb", "rrb");
		push(stack_a, stack_b, "pb");
	}
}

void	push_to_a(t_int_arr *stack_a, t_int_arr *stack_b)
{
	int	max_v;
	int	nearest;

	while (stack_b->size)
	{
		max_v = max_value(stack_a);
		if (stack_b->array[0] < max_v)
		{
			nearest = nearest_larfer_i(stack_a, stack_b->array[0]);
			rotate_to(stack_a, stack_a->array[nearest], "ra", "rra");
		}
		else
			rotate_to(stack_a, min_value(stack_a), "ra", "rra");
		push(stack_b, stack_a, "pa");
	}
}
