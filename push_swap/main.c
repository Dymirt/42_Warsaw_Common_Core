/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:00:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/20 02:05:59 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorted_percent(int *stack, int size);
int		ft_sorted_percent_rev(int *stack, int size);
int		moves(t_int_arr *s, int value);
int		optimal_value_for_push(t_int_arr *stack_a, t_int_arr *stack_b);
void	push_to_b(t_int_arr *stack_a, t_int_arr *stack_b);
void	push_to_a(t_int_arr *stack_a, t_int_arr *stack_b);

int	main(int argc, char **argv)
{
	struct int_arr	*stack_a;
	struct int_arr	*stack_b;

	stack_a = init_stak_a(argc, argv);
	stack_b = init_stak_b(stack_a);
	while (ft_sorted_percent(stack_a->array, stack_a->size) + ft_sorted_percent_rev(stack_a->array, stack_a->size) < 99)
	{
		if (check_swap(stack_a) && stack_a->size == 3)
			swap_head(stack_a->array, "sa");
		else if (stack_b->size == 0)
		{
			while (stack_b->size < 2)
				push(stack_a, stack_b, "pb");
		}
		else
			push_to_b(stack_a, stack_b);
	}
	push_to_a(stack_a, stack_b);
	sort_rotate(stack_a);
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}

void	push_to_b(t_int_arr *stack_a, t_int_arr *stack_b)
{
	int	i_optimal;
	int	max_v;
	int	min_v;
	int	max_i;
	int	nearest;

	min_v = min_value(stack_b);
	i_optimal = optimal_value_for_push(stack_a, stack_b);
	if (i_optimal != 0)
	{
		if (i_optimal < (stack_a->size - i_optimal))
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
	}
	else if (stack_a->array[0] > min_v)
	{
		nearest = nearest_smaller_v(stack_b, stack_a->array[0]);
		while (nearest != 0)
		{
			if (nearest < (stack_b->size - nearest))
				rotate(stack_b, "rb");
			else
				reverse_rotate(stack_b, "rrb");
			nearest = nearest_smaller_v(stack_b, stack_a->array[0]);
		}
		push(stack_a, stack_b, "pb");
	}
	else
	{
		max_v = max_value(stack_b);
		while (stack_b->array[0] != max_v)
		{
			max_i = get_index(stack_b, max_v);
			if (max_i < (stack_b->size - max_i))
				rotate(stack_b, "rb");
			else
				reverse_rotate(stack_b, "rrb");
		}
		push(stack_a, stack_b, "pb");
	}
}

void	push_to_a(t_int_arr *stack_a, t_int_arr *stack_b)
{
	int	max_v;
	int	min_v;
	int	min_i;
	int	nearest;

	while (stack_b->size)
	{
		max_v = max_value(stack_a);
		if (stack_b->array[0] < max_v)
		{
			nearest = nearest_larfer_v(stack_a, stack_b->array[0]);
			while (nearest != 0)
			{
				if (nearest < (stack_a->size - nearest))
					rotate(stack_a, "ra");
				else
					reverse_rotate(stack_a, "rra");
				nearest = nearest_larfer_v(stack_a, stack_b->array[0]);
			}
		}
		else
		{
			min_v = min_value(stack_a);
			while (stack_a->array[0] != min_v)
			{
				min_i = get_index(stack_a, min_v);
				if (min_i < (stack_a->size - min_i))
					rotate(stack_a, "ra");
				else
					reverse_rotate(stack_a, "rra");
			}
		}
		push(stack_b, stack_a, "pa");
	}
}

int	ft_sorted_percent(int *stack, int size)
{
	int	i;
	int	sorted;
	int	percent;

	i = 0;
	sorted = stack[0] > stack[size - 1];
	while (i < size - 1)
	{
		if (stack[i] < stack[i + 1])
			sorted++;
		else
			break ;
		i++;
	}
	percent = (sorted * 100) / size;
	return (percent);
}

int	ft_sorted_percent_rev(int *stack, int size)
{
	int	i;
	int	sorted;
	int	percent;

	i = size - 1;
	sorted = (stack[0] > stack[size - 1]);
	while (i > 0)
	{
		if (stack[i - 1] < stack[i])
			sorted++;
		else
			break ;
		i--;
	}
	percent = (sorted * 100) / size;
	return (percent);
}

int	moves(t_int_arr *s, int value)
{
	int	moves_up;
	int	moves_down;

	moves_up = nearest_smaller_v(s, value);
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
