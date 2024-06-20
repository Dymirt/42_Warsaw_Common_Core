/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:00:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/20 14:08:02 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorted_percent(t_int_arr *stack);
int		ft_sorted_percent_rev(t_int_arr *stack);
void	push_to_b(t_int_arr *stack_a, t_int_arr *stack_b);
void	push_to_a(t_int_arr *stack_a, t_int_arr *stack_b);

int	main(int argc, char **argv)
{
	struct int_arr	*stack_a;
	struct int_arr	*stack_b;

	stack_a = init_stak_a(argc, argv);
	stack_b = init_stak_b(stack_a);
	while (ft_sorted_percent(stack_a) + ft_sorted_percent_rev(stack_a) < 99)
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
	rotate_to(stack_a, min_value(stack_a), "ra", "rra");
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}

int	ft_sorted_percent(t_int_arr *stack)
{
	int	i;
	int	sorted;
	int	percent;

	i = 0;
	sorted = stack->array[0] > stack->array[stack->size - 1];
	while (i < stack->size - 1)
	{
		if (stack->array[i] < stack->array[i + 1])
			sorted++;
		else
			break ;
		i++;
	}
	percent = (sorted * 100) / stack->size;
	return (percent);
}

int	ft_sorted_percent_rev(t_int_arr *stack)
{
	int	i;
	int	sorted;
	int	percent;

	i = stack->size - 1;
	sorted = (stack->array[0] > stack->array[stack->size - 1]);
	while (i > 0)
	{
		if (stack->array[i - 1] < stack->array[i])
			sorted++;
		else
			break ;
		i--;
	}
	percent = (sorted * 100) / stack->size;
	return (percent);
}
