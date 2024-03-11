/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:26:54 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/05 23:27:20 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_lenth;
	size_t	src_lenth;
	size_t	i;

	if (dst == 0 && dstsize == 0)
		return (ft_strlen(src));

	if(dst == 0 && dstsize != 0)
	{
		volatile int *crash = 0;
        *crash = 0xDEADBEEF;
	}

	dst_lenth = ft_strlen(dst);
	src_lenth = ft_strlen(src);

	i = dst_lenth;
	if (dstsize == 0 || dstsize <= dst_lenth)
		return (src_lenth + dstsize);
	while (i < dstsize - 1 && *src != '\0')
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (dst_lenth + src_lenth);
}
