/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:59:37 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/05 21:51:56 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char  *dstptr;
	dstptr = (unsigned char *)dst;

	if (dst == 0 && src == 0)
	{
		return (dst);
	}

	if ((dst == 0 && src == dst) || (src == 0 && src == dst ))
	{

		volatile int *crash = NULL;
        *crash = 0xDEADBEEF;
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
