/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:53:52 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 18:00:40 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sorted_percent(t_int_arr *stack);
int		ft_sorted_percent_rev(t_int_arr *stack);

int	nearly_sorted(t_int_arr *stack)
{
	return (ft_sorted_percent(stack) + ft_sorted_percent_rev(stack) >= 99);
}

int	ft_sorted_percent(t_int_arr *stack)
{
	int	i;
	int	sorted;
	int	percent;

	i = 0;
	sorted = stack->array[0] > stack->array[stack->size - 1];
	while (i < stack->size - 1)
	{
		if (stack->array[i] < stack->array[i + 1])
			sorted++;
		else
			break ;
		i++;
	}
	percent = (sorted * 100) / stack->size;
	return (percent);
}

int	ft_sorted_percent_rev(t_int_arr *stack)
{
	int	i;
	int	sorted;
	int	percent;

	i = stack->size - 1;
	sorted = (stack->array[0] > stack->array[stack->size - 1]);
	while (i > 0)
	{
		if (stack->array[i - 1] < stack->array[i])
			sorted++;
		else
			break ;
		i--;
	}
	percent = (sorted * 100) / stack->size;
	return (percent);
}
