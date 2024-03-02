/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:59:30 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/02 15:59:58 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memmove(void *dst, const void *src, int len)
{
    char *d = dst;
    const char *s = src;

    if (d < s)
    {
        while (len > 0)
        {
            *d++ = *s++;
			len--;
        }
    }
    else if (d > s)
    {
        d = d + len - 1;
        s = s + len - 1;

        while (len > 0)
        {
            *d-- = *s--;
			len--;
        }
    }

    return dst;
}
