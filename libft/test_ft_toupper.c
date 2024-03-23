/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:35:59 by dkolida           #+#    #+#             */
/*   Updated: 2024/02/26 19:42:00 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <assert.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i;


    char test_cases[] = "Hello 2 World";

    for (i = 0; i < 14; i++)
        if (ft_toupper(test_cases[i]) != toupper(test_cases[i]))
        {
            printf("BAD %d != %d\n", ft_toupper(test_cases[i]), toupper(test_cases[i]) );
            return 1;
        }
    printf("OK\n");
    return 0;
}