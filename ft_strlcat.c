/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:26:54 by dkolida           #+#    #+#             */
/*   Updated: 2024/02/26 15:11:10 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_lenth;
	unsigned int	src_lenth;
	unsigned int	i;

	dest_lenth = 0;
	src_lenth = 0;
	while (dest[dest_lenth] != '\0')
		dest_lenth++;
	while (src[src_lenth] != '\0')
		src_lenth++;
	i = dest_lenth;
	if (size == 0 || size <= dest_lenth)
		return (src_lenth + size);
	while (i < size - 1 && *src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest_lenth + src_lenth);
}
