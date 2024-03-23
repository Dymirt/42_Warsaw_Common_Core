#include "libft.h"

void test_ft_itoa();

int main() {
	test_ft_itoa();
	return 0;
}

void test_ft_itoa()
{
    // Test case 1: Positive number
    int num1 = 12345;
    char *result1 = ft_itoa(num1);
    printf("Test 1: ft_itoa(%d) - Result: %s - %s\n", num1, result1,
        num1 == atoi(result1) ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free(result1);

    // Test case 2: Negative number
    int num2 = -98765;
    char *result2 = ft_itoa(num2);
    printf("Test 2: ft_itoa(%d) - Result: %s - %s\n", num2, result2,
        num2 == atoi(result2) ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free(result2);

    // Test case 3: Zero
    int num3 = 0;
    char *result3 = ft_itoa(num3);
    printf("Test 3: ft_itoa(%d) - Result: %s - %s\n", num3, result3,
        num3 == atoi(result3) ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free(result3);

    // Test case 4: Minimum integer value
    int num4 = -2147483648;
    char *result4 = ft_itoa(num4);
    printf("Test 4: ft_itoa(%d) - Result: %s - %s\n", num4, result4,
        num4 == atoi(result4) ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free(result4);

    // Test case 5: Maximum integer value
    int num5 = 2147483647;
    char *result5 = ft_itoa(num5);
    printf("Test 5: ft_itoa(%d) - Result: %s - %s\n", num5, result5,
        num5 == atoi(result5) ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free(result5);

    // Test case 6: One
    int num6 = 1;
    char *result6 = ft_itoa(num6);
    printf("Test 6: ft_itoa(%d) - Result: %s - %s\n", num6, result6,
        num6 == atoi(result6) ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free(result6);
}
