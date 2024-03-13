#include "libft.h"
#include <string.h>

void test_ft_strjoin();

int main() {
	test_ft_strjoin();
}


void test_ft_strjoin()
{
       // Test case 1: non-empty strings
       char *result1 = ft_strjoin("Hello ", "World!");
       char *expected1 = "Hello World!";
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strjoin(\"Hello \", \"World!\") - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: empty strings
       char *result2 = ft_strjoin("", "");
       char *expected2 = "";
       result = strcmp(result2, expected2) == 0;
       printf("Test 2: ft_strjoin(\"\", \"\") - Result: %s, Expected: %s - %s\n",
              result2, expected2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
       free(result1);
       free(result2);
}
