/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:58:04 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/02/29 00:23:29 by dmytrokolid      ###   ########.fr       */
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
