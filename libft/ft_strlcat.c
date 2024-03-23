/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:26:54 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/16 17:55:08 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_lenth;
	size_t			src_lenth;
	size_t			i;

	if (dst == 0 && dstsize == 0)
		return (ft_strlen(src));
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
