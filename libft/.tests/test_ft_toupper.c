/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:35:59 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/24 03:04:59 by dmytrokolid      ###   ########.fr       */
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
            ft_printf("BAD %d != %d\n", ft_toupper(test_cases[i]), toupper(test_cases[i]) );
            return 1;
        }
    ft_printf("OK\n");
    return 0;
}
