/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:39:55 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/05 23:37:26 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;

	s_len = ft_strlen(s);

	dest = (char *)malloc((s_len + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	return (ft_memcpy(dest, (char *)s, s_len + 1));
}
