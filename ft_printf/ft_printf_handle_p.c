/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:05:58 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/14 17:06:12 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_p(uintptr_t nbr, size_t *res, char **p_str)
{
	char	*tmp;
	char	*tmp2;
	size_t	tmp_len;

	tmp2 = ft_utoa_base(nbr, BASE_16);
	if (tmp2[0] == '0')
		tmp = ft_strdup("(nil)");
	else
		tmp = ft_strjoin("0x", tmp2);
	free(tmp2);
	tmp_len = ft_strlen(tmp);
	printf_join(p_str, tmp, res, tmp_len);
}
