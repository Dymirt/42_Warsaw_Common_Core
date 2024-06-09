/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:06:59 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/09 19:34:29 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_head(int *stack, char *str)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (*str)
		ft_putendl_fd(str, 1);
}

void	ss(int *stack_a, int *stack_b)
{
	swap_head(stack_a, "");
	swap_head(stack_b, "");
	ft_putendl_fd("ss", 1);
}

int	check_swap(t_int_arr *stack)
{
	return (stack->array[0] > stack->array[1] && stack->array[0] < stack->array[stack->size - 1]);
}
