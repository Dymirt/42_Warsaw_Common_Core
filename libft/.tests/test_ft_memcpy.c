/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:05:53 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/25 20:12:34 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void test_ft_memcpy();

int main ()
{
	test_ft_memcpy();

	void *dest = 0;
	void *src = 0;

	if(ft_memcpy(dest, src, 0) != memcpy(dest, src, 0))
	{
		ft_printf("%sKO %p, %p", RED, memcpy(dest, src, 0), ft_memcpy(dest, src, 0));
	}
	else
	{
		ft_printf("%sOK ", GREEN);
	}

	dest = malloc(1);
	if (!dest)
		ft_printf("%s Allocating mamory fail\n", RED);

	if(ft_memcpy(dest, src, 0) != memcpy(dest, src, 0))
	{
		ft_printf("%sKO %p, %p", RED, memcpy(dest, src, 0), ft_memcpy(dest, src, 0));
	}
	else
	{
		ft_printf("%sOK ", GREEN);
	}
	free(dest);

	dest = 0;
	src = malloc(1);
	if (!src)
		ft_printf("%s Allocating mamory fail\n", RED);

	if(ft_memcpy(dest, src, 0) != memcpy(dest, src, 0))
	{
		ft_printf("%sKO %p, %p", RED, memcpy(dest, src, 0), ft_memcpy(dest, src, 0));
	}
	else
	{
		ft_printf("%sOK ", GREEN);
	}

	if(ft_memcpy(NULL, "segfaulter tu dois", 17) != 0)
	{
		ft_printf("%sKO %p ", RED, ft_memcpy(NULL, "segfaulter tu dois", 17));
	}
	else
	{
		ft_printf("%sOK ", GREEN);
	}

	ft_printf("%s\n", NORMAL);


}

void test_ft_memcpy()
{
    // Test case 1: copying from a non-empty source to a non-empty destination
    char source1[10] = "Hello";
    char destination1[10] = "World";
    char expected1[10] = "World";

    ft_memcpy(destination1, source1, 5);
    memcpy(expected1, source1, 5);
    int result1 = memcmp(destination1, expected1, sizeof(destination1)) == 0;
    ft_printf("Test 1: ft_memcpy(\"World\", \"Hello\", 5) - Result: %s, Expected: %s - %s\n",
        destination1, expected1, result1 ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 2: copying from a non-empty source to an empty destination
    char source2[5] = "Test";
    char destination2[5] = "";
    char expected2[5] = "";


    ft_memcpy(destination2, source2, sizeof(source2));
    memcpy(expected2, source2, sizeof(source2));
    int result2 = memcmp(destination2, expected2, sizeof(destination2)) == 0;
    ft_printf("Test 2: ft_memcpy(destination2, source2, sizeof(source2)) - Result: %s, Expected: %s - %s\n",
        destination2, expected2, result2 ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 3: copying from a non-empty source to part of a destination
    char source3[9] = "XXXXXXXX";
    char destination3[9] = "Love You";
    char expected3[9] = "Love You";

    ft_memcpy(destination3 + 3, source3, 4);
    memcpy(expected3 + 3, source3, 4);
    int result3 = memcmp(destination3, expected3, sizeof(destination3)) == 0;
    ft_printf("Test 3: ft_memcpy(\"Love You\" + 3, \"\", 4) - Result: %s, Expected: %s - %s\n",
        destination3, expected3, result3 ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
