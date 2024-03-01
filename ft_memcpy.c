/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:26:55 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/02/28 23:38:54 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dst, const void *src, int n)
{
	char *ptr;
	ptr = dst;
	while (n > 0)
	{
		*ptr = *(char *)src;

		ptr++;
		src++;
		n--;
	}
	return (dst);
}
