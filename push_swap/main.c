/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:00:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/19 23:53:29 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorted_percent(int *stack, int size);
int		ft_sorted_percent_rev(int *stack, int size);
int		moves_required(int *stack, int size, int value);
int		optimal_value_for_push(t_int_arr *stack_a, t_int_arr *stack_b);

t_int_arr	*init_stak_a(int argc, char **argv)
{
	struct int_arr	*stack;

	if (argc < 2)
	{
		exit(0);
	}
	stack = valid_input(argc, argv);
	if (!stack->array)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	if (stack->size < 2)
	{
		free(stack->array);
		free(stack);
		exit(0);
	}
	return (stack);
}

t_int_arr	*init_stak_b(t_int_arr *stack_a)
{
	struct int_arr	*stack;

	stack = (struct int_arr *)malloc(sizeof(struct int_arr));
	if (stack)
	{
		stack->size = 0;
		stack->array = (int *)malloc(sizeof(int) * stack_a->size);
		if (stack->array)
			return (stack);
		else
		{
			free(stack);
			stack = NULL;
		}
	}
	free(stack_a->array);
	free(stack_a);
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	main(int argc, char **argv)
{
	struct int_arr	*stack_a;
	struct int_arr	*stack_b;
	int				i_optimal;

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
		{
			i_optimal = optimal_value_for_push(stack_a, stack_b);
			if (i_optimal != 0)
			{
				if (i_optimal < (stack_a->size - i_optimal))
					rotate(stack_a, "ra");
				else
					reverse_rotate(stack_a, "rra");
			}
			else if (stack_a->array[0] > edge_value(stack_b->array, stack_b->size, ft_is_smaller))
			{
				while (nearest_smaller_value(stack_b->array, stack_b->size, stack_a->array[0]) != 0)
				{
					if (nearest_smaller_value(stack_b->array, stack_b->size, stack_a->array[0]) < (stack_b->size - nearest_smaller_value(stack_b->array, stack_b->size, stack_a->array[0])))
						rotate(stack_b, "rb");
					else
						reverse_rotate(stack_b, "rrb");
				}
				push(stack_a, stack_b, "pb");
			}
			else
			{
				while (stack_b->array[0] != edge_value(stack_b->array, stack_b->size, ft_is_larger))
				{
					if (max_value_index(stack_b->array, stack_b->size) < (stack_b->size - max_value_index(stack_b->array, stack_b->size)))
						rotate(stack_b, "rb");
					else
						reverse_rotate(stack_b, "rrb");
				}
				push(stack_a, stack_b, "pb");
			}
		}
	}
	while (stack_b->size)
	{
		if (stack_b->array[0] < edge_value(stack_a->array, stack_a->size, ft_is_larger))
		{
			while (nearest_larger_value(stack_a->array, stack_a->size, stack_b->array[0]) != 0)
			{
				if (nearest_larger_value(stack_a->array, stack_a->size, stack_b->array[0]) < (stack_a->size - nearest_larger_value(stack_a->array, stack_a->size, stack_b->array[0])))
					rotate(stack_a, "ra");
				else
					reverse_rotate(stack_a, "rra");
			}
			push(stack_b, stack_a, "pa");
		}
		else
		{
			while (stack_a->array[0] != edge_value(stack_a->array, stack_a->size, ft_is_smaller))
			{
				if (min_value_index(stack_a->array, stack_a->size) < (stack_a->size - min_value_index(stack_a->array, stack_a->size)))
					rotate(stack_a, "ra");
				else
					reverse_rotate(stack_a, "rra");
			}
			push(stack_b, stack_a, "pa");
		}
	}
	sort_rotate(stack_a);
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}

char *debug_stack(t_int_arr *stack)
{
	char *str;
	char *tmp;
	int i;

	i = 0;
	str = ft_strdup("Stack: ");
	while (i < stack->size)
	{
		tmp = ft_itoa(stack->array[i]);
		str = ft_strjoin(str, tmp);
		str = ft_strjoin(str, " ");
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (str);
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



int	moves_required(int *stack, int size, int value)
{
	int	moves_up;
	int	moves_down;

	moves_up = nearest_smaller_value(stack, size, value);
	moves_down = size - nearest_smaller_value(stack, size, value);
	if (moves_up < moves_down)
		return (moves_up);
	else
		return (moves_down);
}

int	optimal_value_for_push(t_int_arr *s_a, t_int_arr *s_b)
{
	int	i;
	int	min_i;

	i = 0;
	min_i = 0;
	while (i < s_a->size)
	{
		if ((moves_required(s_b->array, s_b->size, s_a->array[min_i]) + min_i) >= (moves_required(s_b->array, s_b->size, s_a->array[i]) + i))
		{
			min_i = i;
		}
		i++;
	}
	return (min_i);
}
