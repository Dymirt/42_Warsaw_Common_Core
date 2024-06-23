/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:11 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/22 15:05:04 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
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
// helpers.c
char	*ft_itoa_wrapper(long long n);
char	*ft_utoa_wrapper(long long n);
char	*ft_ctoa_wrapper(long long n);
char	*ft_utob16_wrapper(long long n);
char	*ft_utob16u_wrapper(long long n);

#endif
