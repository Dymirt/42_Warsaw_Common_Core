/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:29:09 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 00:29:28 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
