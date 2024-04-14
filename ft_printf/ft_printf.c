/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:15 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/14 15:01:41 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vprintf(const char *str, va_list args);
int			ft_swap_and_free(char **str1, char **str2);
void		ft_printf_join(char **print_str, char *str, size_t print_str_len, size_t str_len);
static void	handle_numbers(int *result, char **print_str, int num, char *(*f)());

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	va_start(args, str);
	result = ft_vprintf(str, args);
	va_end(args);
	return (result);
}

int	ft_vprintf(const char *str, va_list args)
{
	int		result;
	char	*print_str;
	char	char_to_str_tmp[3];
	char	*tmp;
	char	*tmp2;
	size_t	tmp_len;

	result = 0;
	ft_bzero(char_to_str_tmp, 3);
	print_str = ft_calloc(1, sizeof(char));
	if (!print_str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd' || *str == 'i')
			{
				handle_numbers(&result, &print_str, va_arg(args, int), &ft_itoa);
			}
			else if (*str == 'u')
			{
				handle_numbers(&result, &print_str, va_arg(args, int), &ft_utoa);
			}
			else if (*str == 's')
			{
				char	*arg = va_arg(args, char *);
				if (arg)
					tmp = ft_strdup(arg);
				else
					tmp = ft_strdup("(null)");
				tmp_len = ft_strlen(tmp);
				ft_printf_join(&print_str, tmp, result, tmp_len);
				result += tmp_len;
			}
			else if (*str == 'c')
			{
				handle_numbers(&result, &print_str, va_arg(args, int), &ft_ctoa);
			}
			else if (*str == 'x')
			{
				tmp = ft_nbr_base(va_arg(args, unsigned int), BASE_16);
				tmp_len = ft_strlen(tmp);
				ft_printf_join(&print_str, tmp, result, tmp_len);
				result += tmp_len;
			}
			else if (*str == 'X')
			{
				tmp = ft_nbr_base(va_arg(args, unsigned int), BASE_16_UPPER);
				tmp_len = ft_strlen(tmp);
				ft_printf_join(&print_str, tmp, result, tmp_len);
				result += tmp_len;
			}
			else if (*str == 'p')
			{
				tmp2 = ft_nbr_base(va_arg(args, uintptr_t), BASE_16);
				if (tmp2[0] == '0')
					tmp = ft_strdup("(nil)");
				else
					tmp = ft_strjoin("0x", tmp2);
				free(tmp2);
				tmp_len = ft_strlen(tmp);
				ft_printf_join(&print_str, tmp, result, tmp_len);
				result += tmp_len;
			}
			else
			{
				ft_printf_join(&print_str, ft_substr(str, 0, 1), result, 1);
				result ++;
			}
		}
		else
		{
			ft_printf_join(&print_str, ft_substr(str, 0, 1), result, 1);
			result++;
		}
		str++;
	}
	write(1, print_str, result);
	free(print_str);
	return (result);
}

int	ft_swap_and_free(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = NULL;
	free(tmp);
	return (1);
}

void	ft_printf_join(char **print_str, char *str, size_t print_str_len, size_t str_len)
{
	char	*tmp;

	tmp = ft_memjoin(*print_str, str, print_str_len, str_len);
	if (!tmp)
	{
		free(*print_str);
		free(str);
		return ;
	}
	free(str);
	ft_swap_and_free(print_str, &tmp);
}

static void	handle_numbers(int *result, char **print_str, int num, char *(*f)())
{
	char	*tmp;
	size_t	tmp_len;

	tmp = f(num);
	if (!num)
		tmp_len = 1;
	else
		tmp_len = ft_strlen(tmp);
	ft_printf_join(print_str, tmp, *result, tmp_len);
	*result += tmp_len;
}
