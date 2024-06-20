/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:03:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/20 17:37:36 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doble_rotate(t_int_arr *s_a, t_int_arr *s_b, int moves_a, int moves_b);

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
	int	optimal;
	int	min_v;
	int	nearest;
	int	moves_a;
	int	moves_b;

	min_v = min_value(stack_b);
	optimal = optimal_value_for_push(stack_a, stack_b);
	moves_a = moves_to_top(stack_a, get_index(stack_a, optimal));
	if (optimal > min_v)
	{
		nearest = nearest_smaller_i(stack_b, optimal);
		moves_b = moves_to_top(stack_b, get_index(stack_b, nearest));
		doble_rotate(stack_a, stack_b, moves_a, moves_b);
		rotate_to(stack_b, nearest, "rb", "rrb");
	}
	else
	{
		moves_b = moves_to_top(stack_b, get_index(stack_b, max_value(stack_b)));
		doble_rotate(stack_a, stack_b, moves_a, moves_b);
		rotate_to(stack_b, max_value(stack_b), "rb", "rrb");
	}
	rotate_to(stack_a, optimal, "ra", "rra");
	push(stack_a, stack_b, "pb");
}

void	push_to_a(t_int_arr *stack_a, t_int_arr *stack_b)
{
	int	max_v;
	int	nearest;

	rotate_to(stack_b, max_value(stack_b), "rb", "rrb");
	while (stack_b->size)
	{
		max_v = max_value(stack_a);
		if (stack_b->array[0] < max_v)
		{
			nearest = nearest_larfer_i(stack_a, stack_b->array[0]);
			rotate_to(stack_a, nearest, "ra", "rra");
		}
		else
			rotate_to(stack_a, min_value(stack_a), "ra", "rra");
		push(stack_b, stack_a, "pa");
	}
}

void	doble_rotate(t_int_arr *s_a, t_int_arr *s_b, int moves_a, int moves_b)
{
	if (moves_a > 0 && moves_b > 0)
		while (moves_a-- && moves_b--)
			rr(s_a, s_b);
	else if (moves_a < 0 && moves_b < 0)
		while (moves_a++ && moves_b++)
			rrr(s_a, s_b);
}

int	optimal_value_for_push(t_int_arr *a, t_int_arr *b)
{
	int	i;
	int	min_i;
	int	moves_total;
	int	min_moves_total;

	i = 0;
	min_i = 0;
	while (i < a->size)
	{
		moves_total = calculate_moves(a, b, i);
		if (moves_total == 0)
			return (a->array[i]);
		if (moves_total < min_moves_total || min_moves_total == 0)
		{
			min_moves_total = moves_total;
			min_i = i;
		}
		i++;
	}
	return (a->array[min_i]);
}
