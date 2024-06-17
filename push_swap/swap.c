/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:06:59 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/16 19:52:02 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_head(int *stack, char *str)
{
	stack[0] = stack[0] ^ stack[1];
	stack[1] = stack[0] ^ stack[1];
	stack[0] = stack[0] ^ stack[1];
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
	int	first;
	int	second;
	int	last;

	first = stack->array[0];
	second = stack->array[1];
	last = stack->array[stack->size - 1];
	if (first < second && first < last && second > last)
		return (1);
	else if (first > second && first < last && second < last)
		return (1);
	else if (first > second && first > last && second > last)
		return (1);
	return (0);
}
