#include "libft.h"
#include <string.h>

void test_ft_memset();

int main() {
	char test_cases[] = "Hello 2 World";
	ft_memset(test_cases, '*', 5);
	if (ft_memset(test_cases, '*', 5) != memset(test_cases, '*', 5))
		ft_printf("%sKO", RED);
    else
	    ft_printf("%sOK", GREEN);
	test_ft_memset();
	return 0;
}

void test_ft_memset()
{
    // Test case 2: filling an entire buffer with a constant value
    char buffer2[5] = "Test";
    char expected2[5] = "Test";

    ft_memset(buffer2, 'X', sizeof(buffer2));
    memset(expected2, 'X', sizeof(expected2));
    int result2 = memcmp(buffer2, expected2, sizeof(buffer2)) == 0;
    ft_printf(result2 ? GREEN "OK " NORMAL : RED "FAIL" NORMAL);

    // Test case 3: filling part of a buffer with a constant value
    char buffer3[9] = {'L', 'o', 'v', 'e', ' ', 'Y', 'o', 'u', 0};
    char expected3[9] = {'L', 'o', 'v', 'e', ' ', 'Y', 'o', 'u', 0};

    ft_memset(buffer3 + 3, 'X', 3);
    memset(expected3 + 3, 'X', 3);
    int result3 = memcmp(buffer3, expected3, sizeof(buffer3)) == 0;
    ft_printf(result3 ? GREEN "OK " NORMAL : RED "FAIL" NORMAL);
    ft_printf("%s\n", NORMAL);
}
