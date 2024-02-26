/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:18:41 by dkolida           #+#    #+#             */
/*   Updated: 2024/02/26 21:23:38 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence = ((void *)0);

	while (*s != '\0')
	{
		if (*s == c)
		{
			last_occurrence = s;
		}
		s++;
	}
	return ((char *)last_occurrence);
}
