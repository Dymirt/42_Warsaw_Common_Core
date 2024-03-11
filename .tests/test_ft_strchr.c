/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:58:13 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/11 20:40:00 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int main() {
    int i;

    char test_cases[][20] = {"", "Hello", "Hello, world!", "tripouille"};

    for (i = 0; i < 3; i++)
    {
        if (ft_strchr(test_cases[i], 'o') != strchr(test_cases[i],'o'))
		{
            printf("%sKO", RED);
        }
            else
        {
            printf("%sOK ", GREEN);
        }


    }
	for (i = 0; i < 3; i++)
    {
        if (ft_strchr(test_cases[i], '\0') != strchr(test_cases[i],'\0'))
        {
            printf("%sKO", RED);
        }
        else
        {
            printf("%sOK ", GREEN);
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (ft_strchr(test_cases[i], 't' + 256) != strchr(test_cases[i],'t' + 256))
        {
            printf("%sKO", RED);
        }
        else
        {
            printf("%sOK ", GREEN);
        }
    }
    printf("%s\n", NORMAL);
    return 0;
}
