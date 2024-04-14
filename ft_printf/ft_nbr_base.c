/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:07 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/14 13:46:38 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ntobase_rec(uintptr_t nbr, char *base, size_t base_len, char **str);

char	*ft_nbr_base(uintptr_t nbr, char *base)
{
	size_t	base_length;
	char	*str;

	if (nbr == 0)
		return (ft_strdup("0"));
	base_length = ft_strlen(base);
	str = ft_calloc(1, sizeof(char));
	ntobase_rec(nbr, base, base_length, &str);
	return (str);
}

static void	ntobase_rec(uintptr_t nbr, char *base, size_t base_len, char **str)
{
	char	*tmp_substr;
	char	*tmp_base_ptr;

	if (nbr >= base_len)
	{
		ntobase_rec(nbr / base_len, base, base_len, str);
	}
	tmp_substr = ft_substr(base, nbr % base_len, 1);
	tmp_base_ptr = ft_strjoin(*str, tmp_substr);
	free(*str);
	*str = tmp_base_ptr;
	free(tmp_substr);
}
