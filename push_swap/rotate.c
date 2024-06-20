/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:07:53 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/20 14:05:21 by dmytrokolid      ###   ########.fr       */
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
	reverse_rotate(stack_a, "");
	reverse_rotate(stack_b, "");
	ft_putendl_fd("rrr", 1);
}

void	rotate_to(t_int_arr *stack, int value, char *r, char *rr)
{
	int	i;
	int	rotate_dir;

	i = get_index(stack, value);
	rotate_dir = i < (stack->size - i);
	while (stack->array[0] != value)
	{
		if (rotate_dir)
			rotate(stack, r);
		else
			reverse_rotate(stack, rr);
	}
}
