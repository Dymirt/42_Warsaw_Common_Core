/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:33:10 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 00:33:19 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*debug_stack(t_int_arr *stack)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	str = ft_strdup("Stack: ");
	while (i < stack->size)
	{
		tmp = ft_itoa(stack->array[i]);
		str = ft_strjoin(str, tmp);
		str = ft_strjoin(str, " ");
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (str);
}
