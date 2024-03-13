#include "libft.h"
#include <string.h>

void test_ft_strtrim();

int main() {
	test_ft_strtrim();
}

void test_ft_strtrim()
{
       // Test case 1: existing character
       char *result1 = ft_strtrim("! Hello! !World  ! ", " !");
       char *expected1 = "Hello! !World";
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strtrim(\"! Hello! !World  ! \", \" !\") - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: character not found in the string
       char *result2 = ft_strtrim("!!Hello! !World!!", "");
       char *expected2 = "!!Hello! !World!!";
       result = strcmp(result2, expected2) == 0;
       printf("Test 2: ft_strtrim(\"!!Hello! !World!!\", \"\") - Result: %s, Expected: %s - %s\n",
              result2, expected2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: character not found in the string
       char *result3 = ft_strtrim("AlohA", "A");
       char *expected3 = "loh";
       result = strcmp(result3, expected3) == 0;
       printf("Test 3: ft_strtrim(\"AlohA\", \"A\") - Result: %s, Expected: %s - %s\n",
              result3, expected3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: character not found in the string
       char *result4 = ft_strtrim(NULL, "ABC");
       result = result4 == NULL;
       printf("Test 4: ft_strtrim(NULL, \"ABC\") - Result: %s, Expected: NULL - %s\n",
              result4,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       free(result1);
       free(result2);
       free(result3);
       free(result4);
}
