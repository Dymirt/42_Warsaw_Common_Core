#include "libft.h"
#include <string.h>

void test_ft_substr();

int main() {
	test_ft_substr();
}

void test_ft_substr()
{
       // Test case 1: Basic substring
       char *result1 = ft_substr("Hello, World!", 7, 5);
       char *expected1 = "World";
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_substr(\"Hello, World!\", 7, 5) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: Substring exceeding string length
       char *result2 = ft_substr("Testing", 0, 20);
       char *expected2 = "Testing";
       result = strcmp(result2, expected2) == 0;
       printf("Test 2: ft_substr(\"Testing\", 0, 20) - Result: %s, Expected: %s - %s\n",
              result2, expected2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: Substring from an empty string
       char *result3 = ft_substr("", 0, 3);
       char *expected3 = "";
       result = strcmp(result3, expected3) == 0;
       printf("Test 3: ft_substr(\"\", 0, 3) - Result: %s, Expected: %s - %s\n",
              result3, expected3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: Empty substring
       char *result4 = ft_substr("Substring", 5, 0);
       char *expected4 = "";
       result = strcmp(result4, expected4) == 0;
       printf("Test 4: ft_substr(\"Substring\", 5, 0) - Result: %s, Expected: %s - %s\n",
              result4, expected4,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 5: Start exceeding string length
       char *result5 = ft_substr("Substring", 20, 5);
       char *expected5 = "";
       result = strcmp(result5, expected5) == 0;
       printf("Test 5: ft_substr(\"Substring\", 20, 5) - Result: %s, Expected: %s - %s\n",
              result5, expected5,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       free(result1);
       free(result2);
       free(result3);
       free(result4);
       free(result5);
}
