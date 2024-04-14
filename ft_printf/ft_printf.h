/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:11 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/14 17:10:49 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

# define BASE_16 "0123456789abcdef"
# define BASE_16_UPPER "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
char	*ft_utoa(unsigned int n);
char	*ft_memjoin(char *s1, char *s2, size_t len1, size_t len2);
char	*ft_utoa_base(uintptr_t nbr, char *base);
char	*ft_ctoa(unsigned int c);
char	*ft_utob16(unsigned int n);
char	*ft_utob16u(unsigned int n);
int		ft_swap_and_free(char **str1, char **str2);
void	ft_printf_handle_s(char *va_sting, size_t *res, char **p_str);
void	ft_printf_handle_p(uintptr_t nbr, size_t *res, char **p_str);
void	printf_join(char **p_str, char *str, size_t *res, size_t str_len);

#endif
