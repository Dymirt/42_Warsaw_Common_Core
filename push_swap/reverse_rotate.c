/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:10:53 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 19:10:17 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_int_arr *stack, char *str)
{
	int	i;
	int	tmp;

	i = stack->size - 1;
	tmp = stack->array[stack->size - 1];
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[i] = tmp;
	if (*str)
		ft_putendl_fd(str, 1);
}

void	rrr(t_int_arr *stack_a, t_int_arr *stack_b)
{
	rotate(stack_a, "");
	rotate(stack_b, "");
	ft_putendl_fd("rrr", 1);
}

int	check_reverse_rotate(t_int_arr *stack)
{
	return (stack->array[stack->size - 1] < stack->array[stack->size - 2]);
}
