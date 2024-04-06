#include "ft_printf.h"

int ft_vprintf(const char *str, va_list args);
int ft_swap_and_free(char **str1, char **str2);

int    ft_printf(const char *str, ...)
{
	va_list args;
	int	result;

	va_start(args, str);
	result = ft_vprintf(str, args);
	va_end(args);
	return (result);
}

int ft_vprintf(const char *str, va_list args)
{
	int result = 0;
	char *print_str;
	char *tmp;
	char char_to_str_tmp[2];

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
			{
				tmp = ft_strjoin(print_str, ft_itoa(va_arg(args, int)));
				/*TODO Protect itoa function */
				if (!tmp){
					free(print_str);
					return (-1);
				}
				ft_swap_and_free(&print_str, &tmp);
			}
			else if (*str == 'u')
			{
				tmp = ft_strjoin(print_str, ft_utoa(va_arg(args, unsigned int)));
				/*TODO Protect utoa function */
				if (!tmp){
					free(print_str);
					return (-1);
				}
				ft_swap_and_free(&print_str, &tmp);
			}
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
			/*else if (*str == 'x')
			{
				tmp = ft_strjoin(print_str, ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
				if (!ft_swap_and_free(&print_str, &tmp))
					return (-1);
			}*/
			else
			{
				tmp = ft_strjoin(print_str, ft_substr(str, 0, 1));
				if (!ft_swap_and_free(&print_str, &tmp))
					return (-1);
			}
		}
		else
		{
			tmp = ft_strjoin(print_str, ft_substr(str, 0, 1));
			ft_swap_and_free(&print_str, &tmp);
		}
		str++;
	}
	ft_putstr_fd(print_str, 1);
	result = ft_strlen(print_str);
	free(print_str);
	return (result);
}

int ft_swap_and_free(char **str1, char **str2)
{
	char *tmp = *str1;
	if (!*str2){
		free(*str1);
		return (0);
	}
	*str1 = *str2;
	free(tmp);
	return (1);
}
