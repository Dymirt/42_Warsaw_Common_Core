/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:36:13 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/03 21:41:37 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(const char *nptr);


int	get_sign(const char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if( str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			count *= -1;

		}
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = get_sign(nptr, &i);
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}
