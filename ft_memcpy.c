/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:59:37 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/03 16:42:36 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dst, const void *src, int n)
{
	char *ptr;
	ptr = dst;
	while (n > 0 && ptr && src)
	{
		*ptr = *(char *)src;

		ptr++;
		src++;
		n--;
	}
	return (dst);
}
