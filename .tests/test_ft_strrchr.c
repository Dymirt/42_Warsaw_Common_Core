/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:58:13 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/11 22:32:23 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void test_ft_strrchr();

int main() {
    int i;

    char test_cases[][20] = {"", "Hello", "Hello, world!"};

    for (i = 0; i < 3; i++)
        if (ft_strrchr(test_cases[i], 'o') != strrchr(test_cases[i],'o'))
		{
            printf("BAD\n");
            return 1;
        }
	for (i = 0; i < 3; i++)
	if (ft_strrchr(test_cases[i], '\0') != strrchr(test_cases[i],'\0'))
	{
		printf("BAD\n");
		return 1;
	}
    printf("OK\n");
    test_ft_strrchr();
    return 0;
}

void test_ft_strrchr()
{
       // Test case 1: existing character
       char *result1 = ft_strrchr("Hello World!", 'o');
       char *expected1 = strrchr("Hello World!", 'o');
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strrchr(\"Hello World!\", 'o') - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: character not found in the string
       char *result2 = ft_strrchr("Hello World!", 'x');
       char *expected2 = strrchr("Hello World!", 'x');
       result = result2 == expected2;
       printf("Test 2: ft_strrchr(\"Hello World!\", 'x') - Result: %s, Expected: NULL - %s\n",
              result2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: char is the only char in the string
       char *result3 = ft_strrchr("x", 'x');
       char *expected3 = strrchr("x", 'x');
       result = strcmp(result3, expected3) == 0;
       printf("Test 3: ft_strrchr(\"x\", 'x') - Result: %s, Expected: %s - %s\n",
              result3, expected3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: char is \0
       char *result4 = ft_strrchr("Hello World!", '\0');
       char *expected4 = strrchr("Hello World!", '\0');
       result = strcmp(result4, expected4) == 0;
       printf("Test 4: ft_strrchr(\"Hello World!\", '\\0') - Result: %s, Expected: %s - %s\n",
              result4, expected4,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
