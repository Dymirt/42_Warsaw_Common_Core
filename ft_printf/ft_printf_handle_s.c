/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:04:25 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/14 17:04:56 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_handle_s(char *va_sting, size_t *res, char **p_str)
{
	char	*tmp;
	size_t	tmp_len;

	if (va_sting)
		tmp = ft_strdup(va_sting);
	else
		tmp = ft_strdup("(null)");
	tmp_len = ft_strlen(tmp);
	printf_join(p_str, tmp, res, tmp_len);
}
