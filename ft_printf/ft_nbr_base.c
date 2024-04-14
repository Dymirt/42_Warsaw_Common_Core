/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:07 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/14 13:28:04 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr_base_recursive(uintptr_t nbr, char *base, size_t base_length , char **base_ptr);

char * ft_nbr_base(uintptr_t nbr, char *base)
{
	size_t	base_length;
	char	*base_ptr;

	if (nbr == 0)
    	return (ft_strdup("0"));

	base_length = ft_strlen(base);

	base_ptr = ft_calloc(1, sizeof(char));

	ft_nbr_base_recursive(nbr, base, base_length, &base_ptr);
	return (base_ptr);
}

static void	ft_nbr_base_recursive(uintptr_t nbr, char *base, size_t base_length , char **base_ptr)
{
	char *tmp_substr;
	char *tmp_base_ptr;
	
	if (nbr >= base_length)
	{
		ft_nbr_base_recursive(nbr / base_length, base, base_length, base_ptr);
	}
	tmp_substr = ft_substr(base, nbr % base_length, 1);
	tmp_base_ptr = ft_strjoin(*base_ptr, tmp_substr);
	free(*base_ptr);
	*base_ptr = tmp_base_ptr;
	free(tmp_substr);
}
