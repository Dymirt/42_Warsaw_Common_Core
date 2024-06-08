/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:03:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 16:06:16 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *stack_a, int *stack_b, int *size_a, int *size_b, char *str)
{
	int	i;

	i = *size_b;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	(*size_b)++;
	(*size_a)--;
	i = 0;
	while (i < *size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	ft_putendl_fd(str, 1);
}
