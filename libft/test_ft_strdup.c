#include "libft.h"
#include <string.h>

void test_ft_strdup();

int main() {
	test_ft_strdup();
	return 0;
}

void test_ft_strdup()
{
    // Test case 1: Basic string duplication
    char str1[] = "Hello, World!";
    char *result1 = ft_strdup(str1);
    char *expected1 = strdup(str1);
    int result = strcmp(expected1, result1) == 0;
    printf("Test 1: ft_strdup(\"Hello, World!\") - Result: %s, Expected: %s - %s\n", result1, expected1,
        result ? GREEN "Pass" NORMAL : RED "Fail" NORMAL);
    free(result1);
    free(expected1);

    // Test case 2: Empty string
    char str2[] = "";
    char *result2 = ft_strdup(str2);
    char *expected2 = strdup(str2);
    result = strcmp(expected2, result2) == 0;
    printf("Test 2: ft_strdup(\"\") - Result: %s, Expected: %s - %s\n", result2, expected2,
        result ? GREEN "Pass" NORMAL : RED "Fail" NORMAL);
    free(result2);
    free(expected2);

    // Test case 3: String with spaces
    char str3[] = "   Spaces   ";
    char *result3 = ft_strdup(str3);
    char *expected3 = strdup(str3);
    result = strcmp(expected3, result3) == 0;
    printf("Test 3: ft_strdup(\"   Spaces   \") - Result: %s, Expected: %s - %s\n",
    	result3, expected3,
        result ? GREEN "Pass" NORMAL : RED "Fail" NORMAL);
    free(result3);
    free(expected3);

    // Test case 4: String with special characters
    char str4[] = "!@#";
    char *result4 = ft_strdup(str4);
    result = strcmp(str4, result4) == 0;
    printf("Test 4: ft_strdup(\"!@#\") - Result: %s, Expected: %s - %s\n", result4, str4,
        result ? GREEN "Pass" NORMAL : RED "Fail" NORMAL);
    free(result4);
}
