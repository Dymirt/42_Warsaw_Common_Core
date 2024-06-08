/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:10:53 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 16:14:14 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *stack, int size, char *str)
{
	int	i;
	int	tmp;

	i = size - 1;
	tmp = stack[size - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
	if (*str)
		ft_putendl_fd(str, 1);
}

void	rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate(stack_a, size_a, "");
	rotate(stack_b, size_b, "");
	ft_putendl_fd("rrr", 1);
}

int	check_for_rra(int *stack, int size)
{
	return (stack[size - 1] < stack[size - 2]);
}

int	check_for_rrb(int *stack, int size)
{
	return (stack[size - 1] > stack[size - 2]);
}
