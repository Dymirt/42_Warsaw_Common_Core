/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:03:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 18:13:06 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_int_arr *stack_a, t_int_arr *stack_b, char *str)
{
	int	i;

	i = stack_b->size;
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = stack_a->array[0];
	stack_b->size ++;
	stack_a->size --;
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	ft_putendl_fd(str, 1);
}
