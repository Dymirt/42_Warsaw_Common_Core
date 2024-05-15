#include "libft.h"
#include <string.h>

void test_ft_bzero();

int main() {
	test_ft_bzero();
}


void test_ft_bzero()
{
    // Test case 1: zeroing out a non-empty buffer
    char buffer1[10] = "Hello";
    char expected1[10] = "Hello";

    ft_bzero(buffer1, 1);
    bzero(expected1, 1);
    int result1 = memcmp(buffer1, expected1, sizeof(buffer1)) == 0;
    printf("Test 1: ft_bzero(\"Hello\", 1) - Result: %s, Expected: %s - %s\n",
        buffer1+1, expected1+1, result1 ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 2: zeroing out an entire buffer
    char buffer2[5] = "Test";
    char expected2[5] = "Test";

    ft_bzero(buffer2, sizeof(buffer2) - 1);
    bzero(expected2, sizeof(expected2) - 1);
    int result2 = memcmp(buffer2, expected2, sizeof(buffer2)) == 0;
    printf("Test 2: ft_bzero(\"Test\", sizeof(buffer) - 1) - Result: %s, Expected: %s - %s\n",
        buffer2, expected2, result2 ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 3: zeroing out part of a buffer
    char buffer3[9] = {'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', 0};
    char expected3[9] = {'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', 0};

    ft_bzero(buffer3 + 3, 3);
    bzero(expected3 + 3, 3);
    int result3 = memcmp(buffer3, expected3, sizeof(buffer3)) == 0;
    printf("Test 3: ft_bzero(\"Love You\" + 3, 3) - Result: %s, Expected: %s - %s\n",
        buffer3, expected3, result3 ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
