/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:24:20 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/17 22:24:42 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arr_atoi(char **array, int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[i] = ft_atoi(array[i]);
		i++;
	}
}
