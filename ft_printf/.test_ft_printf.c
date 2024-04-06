/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:22 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/06 21:53:23 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int test_ft_printf(void)
{
	char *str = "Hello, %%% %s%c %u";
	unsigned int max_uint = 4294967295;
	int result = ft_printf(str, "World", '!', max_uint);
	return (result);
}

int main(void)
{
	int result = test_ft_printf();
	printf("\n%x\n", result);
}
