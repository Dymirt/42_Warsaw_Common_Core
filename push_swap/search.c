/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:50:27 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 00:09:55 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value_index(int *stack, int size)
{
	int	i;
	int	max;
	int	index;

	i = 1;
	max = stack[0];
	index = 0;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	min_value_index(int *stack, int size)
{
	int	i;
	int	min;
	int	index;

	i = 1;
	min = stack[0];
	index = 0;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	edge_value(int *stack, int size, int (*f)(int a, int b))
{
	int	i;
	int	edge;

	i = 1;
	edge = stack[0];
	while (i < size)
	{
		if (f(stack[i], edge))
			edge = stack[i];
		i++;
	}
	return (edge);
}

int	nearest_larger_value(int *stack, int size, int value)
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (i < size)
	{
		if ((stack[i] > value))
		{
			if (stack[i] < stack[index] || index == -1)
				index = i;
		}
		i++;
	}
	return (index);
}

int	nearest_smaller_value(int *stack, int size, int value)
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (i < size)
	{
		if ((stack[i] < value))
		{
			if (stack[i] > stack[index] || index == -1)
				index = i;
		}
		i++;
	}
	return (index);
}

int	nearest_value(int *arr, int size, int value, int (*f)(int a, int b))
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (i < size)
	{
		if (f(arr[i], value))
		{
			if (!f(arr[i], arr[index]) || index == -1)
				index = i;
		}
		i++;
	}
	return (index);
}
