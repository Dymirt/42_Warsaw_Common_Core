/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:26:19 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/16 20:26:42 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_int_str(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 11)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' && i == 0 && ft_isdigit(str[i + 1]))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
