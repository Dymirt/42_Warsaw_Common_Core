#include "libft.h"
void test_ft_isalpha();

int main()
{
	test_ft_isalpha();
	return 0;
}

void test_ft_isalpha()
{
       // Test case 1: lower case char
       int result1 = ft_isalpha('h');
       int expected1 = 1;
       int result = result1 == expected1;
       printf("Test 1: ft_isalpha('h') - Result: %d, Expected: %d - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: upper case char
       int result2 = ft_isalpha('H');
       int expected2 = 1;
       result = result2 == expected2;
       printf("Test 2: ft_isalpha('H') - Result: %d, Expected: %d - %s\n",
              result2, expected2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: non-alpha char
       int result3 = ft_isalpha('9');
       int expected3 = 0;
       result = result3 == expected3;
       printf("Test 3: ft_isalpha('9') - Result: %d, Expected: %d - %s\n",
              result3, expected3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: NULL
       int result4 = ft_isalpha(0);
       int expected4 = 0;
       result = result4 == expected4;
       printf("Test 4: ft_isalpha(0) - Result: %d, Expected: %d - %s\n",
              result4, expected4,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
