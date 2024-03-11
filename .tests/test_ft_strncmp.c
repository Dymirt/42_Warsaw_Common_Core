#include "libft.h"
#include <string.h>

void test_ft_strncmp();

int main() {
	test_ft_strncmp();
	return 0;
}


void test_ft_strncmp()
{
       // Test case 1: existing character
       int result1 = ft_strncmp("HeLlo", "Hello", 7);
       int expected1 = strncmp("HeLlo", "Hello", 7);
       int result = !!result1 == !!expected1;
       printf("Test 1: ft_strncmp(\"HeLlo\", \"Hello\", 7) - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
       // Test case 2: character not found in the string
       int result2 = ft_strncmp("HeLlo", "Hello", 0);
       int expected2 = strncmp("HeLlo", "Hello", 0);
       result = !!result2 == !!expected2;
       printf("Test 2: ft_strncmp(\"HeLlo\", \"Hello\", 0) - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: intis the only intin the string
       int result3 = ft_strncmp("Hello", "HeLlo", 7);
       int expected3 = strncmp("Hello", "HeLlo", 7);
       result = !!result3 == !!expected3;
       printf("Test 3: ft_strncmp(\"Hello\", \"HeLlo\", 7) - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: intis \0
       int result4 = ft_strncmp("Hello", "Hello", 7);
       int expected4 = strncmp("Hello", "Hello", 7);
       result = !!result4 == !!expected4;
       printf("Test 4: ft_strncmp(\"Hello\", \"Hello\", 7) - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 5: string is NULL
       int result5 = ft_strncmp("", "Hell", 2);
       int expected5 = strncmp("", "Hell", 2);
       result = !!result5 == !!expected5;
       printf("Test 5: ft_strncmp(\"\", \"Hell\", 2) - Result: %d, Expected: %d - %s\n",
              result5, expected5,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
