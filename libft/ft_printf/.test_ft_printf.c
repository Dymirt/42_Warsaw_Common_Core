/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:22 by dkolida           #+#    #+#             */
/*   Updated: 2024/04/07 17:31:35 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int test_ft_printf(void)
{
	int result;
	result = ft_printf(" '%c' '%c' '%c' ", 0, '1', '2');
	return (result);
}

int main(void)
{
	int result = test_ft_printf();
	printf("\n%d\n", result);
	result = printf(" '%c' '%c' '%c' ", 0, '1', '2');
	printf("\n%d\n", result);

}
