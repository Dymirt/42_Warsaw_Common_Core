#include "libft.h"
#include <ctype.h>

void test_ft_isascii();

int main() {
	if (!!ft_isascii(1) != !!isascii(1))
	{
		printf("BAD case 1\n");
		return 1;
	}

	if (!!ft_isascii('a') != !!isascii('a'))
	{
		printf("BAD case 2\n");
		return 1;
	}

	if (!!ft_isascii(127) != !!isascii(127))
	{
		printf("BAD case 3\n");
		return 1;
	}

	printf("%sOK\n", GREEN);
	printf("%s", NORMAL);

	test_ft_isascii();

	return 0;
}

void test_ft_isascii()
{
       // Test case 1: ascii char: ~
       int result1 = ft_isascii(127);
       int expected1 = 1;
       int result = result1 == expected1;
       printf("Test 1: ft_isascii('~') - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: ascii char: \t
       int result2 = ft_isascii('\t');
       int expected2 = 1;
       result = result2 == expected2;
       printf("Test 2: ft_isascii('\\t') - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: NULL
       int result3 = ft_isascii(0);
       int expected3 = 1;
       result = result3 == expected3;
       printf("Test 3: ft_isascii(0) - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: non-ascii char: below the lower limit
       int result4 = ft_isascii(-20);
       int expected4 = 0;
       result = result4 == expected4;
       printf("Test 4: ft_isascii(-20) - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 5: non-ascii char: above the upper limit
       int result5 = ft_isascii(128);
       int expected5 = 0;
       result = result5 == expected5;
       printf("Test 5: ft_isascii(120) - Result: %d, Expected: %d - %s\n",
              result5, expected5,
              result ? GREEN "PASS" NORMAL  : RED "FAIL" NORMAL);
}
