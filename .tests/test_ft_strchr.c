/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:58:13 by dkolida           #+#    #+#             */
/*   Updated: 2024/02/28 21:23:56 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int main() {
    int i;

    char test_cases[][20] = {"", "Hello", "Hello, world!"};

    for (i = 0; i < 3; i++)
        if (ft_strchr(test_cases[i], 'o') != strchr(test_cases[i],'o'))
		{
            printf("BAD\n");
            return 1;
        }
	for (i = 0; i < 3; i++)
	if (ft_strchr(test_cases[i], '\0') != strchr(test_cases[i],'\0'))
	{
		printf("BAD\n");
		return 1;
	}
    printf("OK\n");
    return 0;
}
