#include "libft.h"
#include <string.h>

void test_ft_memcmp();

int main() {
	test_ft_memcmp();
	return 0;

}

void test_ft_memcmp()
{
    // Test case 1: comparing two equal non-empty buffers
    char buffer1[10] = "Hello";
    char compare1[10] = "Hello";

    int result1 = ft_memcmp(buffer1, compare1, sizeof(buffer1));
    int expected1 = memcmp(buffer1, compare1, sizeof(buffer1));
    int result = result1 == expected1;
    printf("Test 1: ft_memcmp(\"Hello\", \"Hello\", sizeof(\"Hello\")) - Result: %d, Expected: %d - %s\n",
        result1, expected1 ,result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    char buffer2[7] = "Tested";
    char compare2[5] = "Test";

    // Test case 2: comparing part of two buffers
    int result2 = ft_memcmp(buffer2, compare2, 4);
    int expected2 = memcmp(buffer2, compare2, 4);
    result = result2 == expected2;
    printf("Test 2: ft_memcmp(\"Tested\", \"Test\", 4) - Result: %d, Expected: %d - %s\n",
        result1, expected2, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 3: comparing non-equal buffers
    char buffer3[12] = "\0I Love You";
    char compare3[18] = "\0I Don't Love You";

    int result3 = ft_memcmp(buffer3, compare3, 6);
    int expected3 = memcmp(buffer3, compare3, 6);
    result = result3 == expected3;
    printf("Test 3: ft_memcmp(\"\\0I Love You\", \"\\0I Don't Love You\", 6) - Result: %d, Expected: %d - %s\n",
        result3, expected3, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 4: comparing non-equal buffers
    char buffer4[5] = "Hall";
    char compare4[5] = "Hell";

    int result4 = ft_memcmp(buffer4, compare4, 6);
    int expected4 = memcmp(buffer4, compare4, 6);
    result = result4 == expected4;
    printf("Test 4: ft_memcmp(\"Hall\", \"Hell\", 6) - Result: %d, Expected: %d - %s\n",
        result4, expected4, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 5: comparing 0 chars
    int result5 = ft_memcmp(buffer3, compare3, 0);
    int expected5 = memcmp(buffer3, compare3, 0);
    result = result5 == expected5;
    printf("Test 5: ft_memcmp(\"\\0I Love You\", \"\\0I Don't Love You\", 0) - Result: %d, Expected: %d - %s\n",
        result5, expected5, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
