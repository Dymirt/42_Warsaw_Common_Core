/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:58:13 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/11 21:48:00 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void test_ft_strchr();

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

    test_ft_strchr();
    return 0;
}

void test_ft_strchr()
{
       // Test case 1: existing character
       char *result1 = ft_strchr("Hello World!", 'o');
       char *expected1 = strchr("Hello World!", 'o');
       int result = result1 == expected1;
       printf("Test 1: ft_strchr(\"Hello World!\", 'o') - Result: %p, Expected: %p - %s\n",
              (void *)result1, (void *)expected1,
              (result1 == expected1) ? GREEN "PASS" NORMAL
                                     : RED "FAIL" NORMAL);

       // Test case 2: character not found in the string
       char *result2 = ft_strchr("Hello World!", 'x');
       char *expected2 = strchr("Hello World!", 'x');
       result = result2 == expected2;
       printf("Test 2: ft_strchr(\"Hello World!\", 'x') - Result: %p, Expected: NULL - %s\n",
              (void *)result2, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: char is the only char in the string
       char *result3 = ft_strchr("x", 'x');
       char *expected3 = strchr("x", 'x');
       result = result3 == expected3;
       printf("Test 3: ft_strchr(\"x\", 'x') - Result: %p, Expected: %p - %s\n",
              (void *)result3, (void *)expected3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: char is \0
       char *result4 = ft_strchr("Hello World!", '\0');
       char *expected4 = strchr("Hello World!", '\0');
       result = result4 == expected4;
       printf("Test 4: ft_strchr(\"Hello World!\", '\\0') - Result: %p, Expected: %p - %s\n",
              (void *)result4, (void *)expected4,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
