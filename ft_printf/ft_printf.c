/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:15 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/07 14:58:31 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(const char *str, va_list args);
int		ft_swap_and_free(char **str1, char **str2);
void	va_printf_di(char **print_str, va_list args);
void	va_printf_def(const char *str, char **print_str);
void	va_printf_u(char **print_str, va_list args);

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
	char	char_to_str_tmp[2];

	char_to_str_tmp[1] = '\0';
	print_str = ft_calloc(1, sizeof(char));
	if (!print_str)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd' || *str == 'i')
				va_printf_di(&print_str, args);
			else if (*str == 'u')
				va_printf_u(&print_str, args);
			/*
			else if (*str == 's')
			{
				tmp = ft_strjoin(print_str, va_arg(args, char *));
				if (!ft_swap_and_free(&print_str, &tmp))
					return (-1);
			}
			else if (*str == 'c')
			{
				char_to_str_tmp[0] = va_arg(args, int);
				tmp = ft_strjoin(print_str, char_to_str_tmp);
				if (!ft_swap_and_free(&print_str, &tmp))
					return (-1);
			}
			else if (*str == '%')
			{
				tmp = ft_strjoin(print_str, "%");
				if (!ft_swap_and_free(&print_str, &tmp))
					return (-1);
			}
			else if (*str == 'x')
			{
				tmp = ft_strjoin(print_str, ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
				if (!ft_swap_and_free(&print_str, &tmp))
					return (-1);
			}*/
			else
				va_printf_def(str, &print_str);
		}
		else
			va_printf_def(str, &print_str);
		str++;
	}
	ft_putstr_fd(print_str, 1);
	result = ft_strlen(print_str);
	free(print_str);
	return (result);
}

void	va_printf_di(char **print_str, va_list args)
{
	char	*tmp;
	char	*tmp_2;

	tmp_2 = ft_itoa(va_arg(args, int));
	tmp = ft_strjoin(*print_str, tmp_2);
	if (!tmp)
	{
		free(*print_str);
		free(tmp_2);
		return ;
	}
	free(tmp_2);
	ft_swap_and_free(print_str, &tmp);
}

void	va_printf_u(char **print_str, va_list args)
{
	char	*tmp;
	char	*tmp_2;

	tmp_2 = ft_utoa(va_arg(args, unsigned int));
	tmp = ft_strjoin(*print_str, tmp_2);
	if (!tmp)
	{
		free(*print_str);
		free(tmp_2);
		return ;
	}
	free(tmp_2);
	ft_swap_and_free(print_str, &tmp);
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

void	va_printf_def(const char *str, char **print_str)
{
	char	*tmp_substr;
	char	*tmp_str;

	tmp_substr = ft_substr(str, 0, 1);
	tmp_str = ft_strjoin(*print_str, tmp_substr);
	if (!ft_swap_and_free(print_str, &tmp_str))
		return ;
	free(tmp_substr);
}
