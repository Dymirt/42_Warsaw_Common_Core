/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:16:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/11 20:39:21 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	char test_cases[][20] = {
		"0",
		"546:5",
		"Hello, world!",
		"-4886",
		"+548",
		"054854",
		"000074",
		"+-54",
		"-+48",
		"--47",
		"++47",
		"+47+5",
		"-47-5",
		"\e475",
		"\t\n\r\v\f  469 \n",
		"-2147483648",
		"2147483647",
		"\t\n\r\v\fd469 \n",
		"\n\n\n  -46\b9 \n5d6",
		"",
		};

	for (int i = 1; i < 20; i++){
		if (ft_atoi(test_cases[i]) == atoi(test_cases[i]))
			printf("%sOK[%d] ", GREEN, i);
		else
			printf("%sKO[%d] ", RED, i);
	}
	printf("%s\n", NORMAL);
	return (0);
}
