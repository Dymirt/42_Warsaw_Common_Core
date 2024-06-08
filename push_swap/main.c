/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:00:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 18:24:19 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b);

int	main(int argc, char **argv)
{
	struct int_arr	*stack_a;
	struct int_arr	*stack_b;

	stack_a = valid_input(argc, argv);
	if (!stack_a->array)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	stack_b = (struct int_arr *)malloc(sizeof(struct int_arr));
	if (!stack_b)
	{
		free(stack_a->array);
		free(stack_a);
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	stack_b->size = 0;
	stack_b->array = (int *)malloc(sizeof(int) * stack_a->size);
	if (!stack_b->array)
	{
		free(stack_a->array);
		free(stack_a);
		free(stack_b);
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	while (!ft_sorted(stack_a->array, stack_a->size) || stack_b->size)
	{
		//print_stacks(stack_a, stack_b, size_a, size_b);
		if (check_for_rotate(stack_a) && !check_for_rotate(stack_b))
			rr(stack_a, stack_b);
		else if (check_for_rotate(stack_a))
			rotate(stack_a, "ra");
		else if (check_reverse_rotate(stack_a) && !check_reverse_rotate(stack_b))
			rrr(stack_a, stack_b);
		else if (check_reverse_rotate(stack_a))
			reverse_rotate(stack_a, "rra");
		else if (stack_a->array[0] > stack_a->array[1] && stack_b->array[0] < stack_b->array[1] && stack_b->size > 1)
			ss(stack_a->array, stack_b->array);
		else if (stack_a->array[0] > stack_a->array[1] && stack_a->size > 1)
			swap_head(stack_a->array, "sa");
		else if (stack_a->array[0] < stack_a->array[1] && !ft_sorted(stack_a->array, stack_a->size))
			push(stack_a, stack_b, "pb");
		else if (stack_b->size)
			push(stack_b, stack_a,"pa");
		//print_stacks(stack_a, stack_b, size_a, size_b);
	}
	//print_stacks(stack_a, stack_b, size_a, size_b);
		free(stack_a->array);
		free(stack_a);
		free(stack_b->array);
		free(stack_b);
}

void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;

	i = 0;
	ft_putstr_fd("Stack A: ", 1);
	while (i < size_a)
	{
		ft_putnbr_fd(stack_a[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putendl_fd("", 1);
	i = 0;
	ft_putstr_fd("Stack B: ", 1);
	while (i < size_b)
	{
		ft_putnbr_fd(stack_b[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putendl_fd("", 1);
}
