/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:15 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/25 23:44:41 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		str_loop(const char *str, va_list *args, char **p_str, size_t *res);

static void	toa_join(size_t *res, char **p_str, long long num, char *(*f)());
void		handle_p(uintptr_t nbr, size_t *res, char **p_str);
void		match_c(const char *str, va_list *args, char **p_str, size_t *res);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	result;
	char	*p_str;

	result = 0;
	p_str = ft_calloc(1, sizeof(char));
	if (!p_str)
		return (-1);
	va_start(args, str);
	str_loop(str, &args, &p_str, &result);
	va_end(args);
	write(1, p_str, result);
	free(p_str);
	return (result);
}

void	str_loop(const char *str, va_list *args, char **p_str, size_t *res)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			match_c(str, args, p_str, res);
		}
		else
			printf_join(p_str, ft_substr(str, 0, 1), res, 1);
		str++;
	}
}

void	printf_join(char **p_str, char *str, size_t *res, size_t str_len)
{
	char	*tmp;

	tmp = ft_memjoin(*p_str, str, *res, str_len);
	if (!tmp)
	{
		free(*p_str);
		free(str);
		return ;
	}
	free(str);
	ft_swap_and_free(p_str, &tmp);
	*res += str_len;
}

void	toa_join(size_t *res, char **p_s, long long n, char *(*f)(long long))
{
	char	*tmp;
	size_t	tmp_len;

	tmp = f(n);
	if (tmp[0] == 0 && tmp[1] == '\0')
		tmp_len = 1;
	else
		tmp_len = ft_strlen(tmp);
	printf_join(p_s, tmp, res, tmp_len);
}

void	match_c(const char *c, va_list *args, char **p_str, size_t *res)
{
	if (*c == 'd' || *c == 'i')
		toa_join(res, p_str, va_arg(*args, int), &ft_itoa_wrapper);
	else if (*c == 'u')
		toa_join(res, p_str, va_arg(*args, int), &ft_utoa_wrapper);
	else if (*c == 's')
		ft_printf_handle_s(va_arg(*args, char *), res, p_str);
	else if (*c == 'c')
		toa_join(res, p_str, (va_arg(*args, int)), &ft_ctoa_wrapper);
	else if (*c == 'x')
		toa_join(res, p_str, va_arg(*args, int), &ft_utob16_wrapper);
	else if (*c == 'X')
		toa_join(res, p_str, va_arg(*args, int), &ft_utob16u_wrapper);
	else if (*c == 'p')
		ft_printf_handle_p(va_arg(*args, uintptr_t), res, p_str);
	else
		printf_join(p_str, ft_substr(c, 0, 1), res, 1);
}
