/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:00:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 17:02:47 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int		check_sort(int *stack_a, int size);
void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b);

int	main(int argc, char **argv)
{
	int				size_a;
	int				size_b = 0;
	int				*stack_a;
	int				*stack_b;
	struct array	*array;

	array = valid_input(argc, argv);
	if (!array->array)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	size_a = array->size;
	stack_a = array->array;
	stack_b = ft_calloc(size_a, sizeof(int));
	while (!check_sort(stack_a, size_a) || size_b)
	{
		//print_stacks(stack_a, stack_b, size_a, size_b);
		if (check_for_ra(stack_a, size_a) && check_for_rb(stack_b, size_b))
			rr(stack_a, stack_b, size_a, size_b);
		else if (check_for_ra(stack_a, size_a))
			rotate(stack_a, size_a, "ra");
		else if (check_for_rra(stack_a, size_a) && check_for_rrb(stack_b, size_b))
			rrr(stack_a, stack_b, size_a, size_b);
		else if (check_for_rra(stack_a, size_a))
			reverse_rotate(stack_a, size_a, "rra");
		else if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1] && size_b > 1)
			ss(stack_a, stack_b);
		else if (stack_a[0] > stack_a[1] && size_a > 1)
			swap_head(stack_a, "sa");
		else if (stack_a[0] < stack_a[1] && !check_sort(stack_a, size_a))
			push(stack_a, stack_b, &size_a, &size_b, "pb");
		else if (size_b)
			push(stack_b, stack_a, &size_b, &size_a, "pa");
		//print_stacks(stack_a, stack_b, size_a, size_b);
	}
	//print_stacks(stack_a, stack_b, size_a, size_b);
	free(array->array);
	free(array);
	free(stack_b);
}

int	check_sort(int *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
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
