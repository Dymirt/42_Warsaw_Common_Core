/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:32:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/02 19:05:33 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memchr(const void *s, int c, int n)
{
    char *p = (char *)s; // Casting s to unsigned char pointer for byte-wise comparison
	int i;
	i = 0;
    while (i < n)
	{
        if (p[i] == (char)c) // Comparing byte-wise
            return (void *)(p + i); // Returning pointer to the occurrence
		i++;
    }

    return (0); // If not found
}
