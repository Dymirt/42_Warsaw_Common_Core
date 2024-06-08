/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:07:53 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 18:23:03 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_int_arr *stack, char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->array[0];
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = tmp;
	if (*str)
		ft_putendl_fd(str, 1);
}

void	rr(t_int_arr *stack_a, t_int_arr *stack_b)
{
	rotate(stack_a, "");
	rotate(stack_b, "");
	ft_putendl_fd("rr", 1);
}

int	check_for_rotate(t_int_arr *stack)
{
	return (stack->array[0] > stack->array[stack->size - 1]);
}
