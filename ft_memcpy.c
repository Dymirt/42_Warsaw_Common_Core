/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:59:37 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/16 17:47:55 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstptr;

	dstptr = (unsigned char *)dst;
	if (dst == 0 && src == 0)
	{
		return (dst);
	}
	while (n > 0)
	{
		*dstptr = *(unsigned char *)src;
		dstptr++;
		src++;
		n--;
	}
	return (dst);
}

/*
	if ((dst == 0 && src == dst) || (src == 0 && src == dst ))
	{
		volatile int *crash = NULL;
		*crash = 0xDEADBEEF;
	}
*/
