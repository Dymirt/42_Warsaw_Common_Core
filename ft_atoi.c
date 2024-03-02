/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:36:13 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/02 20:13:46 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int	get_sign(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if( str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			count *= -1;

		}
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = get_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

/*
int main(void)
{
	printf("%d\n", ft_atoi(" ---+--214758364b567"));
	printf("%d\n", ft_atoi(" ---+--2147483648ab567"));
	printf("%d\n", ft_atoi(" ---+---214748f3648ab567"));

	printf("%d\n", ft_atoi(" ---+--214748-3648ab567"));

	printf("%d\n", ft_atoi(" ---+---2-14748-3648ab567"));

	printf("%d\n", ft_atoi(" ---+-0-3648ab567"));
	printf("%d\n", ft_atoi(" - +--+---214748-3648ab567"));
	printf("%d\n", ft_atoi("  - +--+---214748-3648ab567"));
	printf("%d\n", ft_atoi("--580764829"));

	printf("%d\n", ft_atoi("  ---+--+01234506789ab567"));
	printf("%d\n", ft_atoi("  ---+--+01234506789ab567"));
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_atoi("0"));
	else if (arg == 2)
		ft_print_result(ft_atoi("546:5"));
	else if (arg == 3)
		ft_print_result(ft_atoi("-4886"));
	else if (arg == 4)
		ft_print_result(ft_atoi("+548"));
	else if (arg == 5)
		ft_print_result(ft_atoi("054854"));
	else if (arg == 6)
		ft_print_result(ft_atoi("000074"));
	else if (arg == 7)
		ft_print_result(ft_atoi("+-54"));
	else if (arg == 8)
		ft_print_result(ft_atoi("-+48"));
	else if (arg == 9)
		ft_print_result(ft_atoi("--47"));
	else if (arg == 10)
		ft_print_result(ft_atoi("++47"));
	else if (arg == 11)
		ft_print_result(ft_atoi("+47+5"));
	else if (arg == 12)
		ft_print_result(ft_atoi("-47-5"));
	else if (arg == 13)
		ft_print_result(ft_atoi("\e475"));
	else if (arg == 14)
		ft_print_result(ft_atoi("\t\n\r\v\f  469 \n"));
	else if (arg == 15)
		ft_print_result(ft_atoi("-2147483648"));
	else if (arg == 16)
		ft_print_result(ft_atoi("2147483647"));
	else if (arg == 17)
		ft_print_result(ft_atoi("\t\n\r\v\fd469 \n"));
	else if (arg == 18)
		ft_print_result(ft_atoi("\n\n\n  -46\b9 \n5d6"));
	else if (arg == 19)
		ft_print_result(ft_atoi(""));

}
//*/
