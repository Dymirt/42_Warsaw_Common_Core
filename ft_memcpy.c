/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:59:37 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/03 17:48:44 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char  *dstptr;
	dstptr = (unsigned char *)dst;
	while (n > 0)
	{
		*dstptr = *(unsigned char *)src;

		dstptr++;
		src++;
		n--;
	}
	return (dst);
}
