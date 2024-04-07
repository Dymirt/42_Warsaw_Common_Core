/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:15 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/07 17:33:54 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(const char *str, va_list args);
int		ft_swap_and_free(char **str1, char **str2);
void	ft_printf_join(char **print_str, char *str);

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
	char	*tmp;

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
				ft_printf_join(&print_str, ft_itoa(va_arg(args, int)));
			else if (*str == 'u')
				ft_printf_join(&print_str, ft_utoa(va_arg(args, unsigned int)));
			else if (*str == 's')
			{	
				char *arg = va_arg(args, char *);
				if (arg)
					tmp = ft_strdup(arg);
				else
					tmp = ft_strdup("(null)");
				ft_printf_join(&print_str, tmp);
			}		
			else if (*str == 'c')
			{
				char_to_str_tmp[0] = va_arg(args, int);
				ft_printf_join(&print_str, ft_strdup(char_to_str_tmp));
				# TODO result is not correct for case when char is 0
			}
			/*
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
				ft_printf_join(&print_str, ft_substr(str, 0, 1));
		}
		else
			ft_printf_join(&print_str, ft_substr(str, 0, 1));
		str++;
	}
	ft_putstr_fd(print_str, 1);
	result = ft_strlen(print_str);
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

void	ft_printf_join(char **print_str, char *str)
{
	char	*tmp;

	tmp = ft_strjoin(*print_str, str);
	if (!tmp)
	{
		free(*print_str);
		free(str);
		return ;
	}
	free(str);
	ft_swap_and_free(print_str, &tmp);
}
