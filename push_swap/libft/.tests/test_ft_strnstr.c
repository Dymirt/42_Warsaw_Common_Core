#include "libft.h"
#include <string.h>

void test_ft_strnstr();

int main() {
	test_ft_strnstr();
}

void test_ft_strnstr()
{
       // Test case 1: substr exists within the buffer
       printf("%s", RED);
       char *result1 = ft_strnstr("Hello World!", "ell", 7);
       char *expected1 = "ello World!";
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strnstr(\"Hello World!\", \"ell\", 7) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: substr not found in the string
       printf("%s", RED);
       char *result2 = ft_strnstr("Hello World!", "Woo", 20);
       result = result2 == NULL;
       printf("Test 2: ft_strnstr(\"Hello World!\", \"Woo\", 20) - Result: %s, Expected: NULL - %s\n",
              result2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: substr not found in the string within the buffer size
       printf("%s", RED);
       char *result3 = ft_strnstr("Hello World!", "World", 9);
       result = result3 == NULL;
       printf("Test 3: ft_strnstr(\"Hello World!\", \"World\", 9) - Result: %s, Expected: NULL - %s\n",
              result3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: char is \0
        printf("%s", RED);
       char *result4 = ft_strnstr("Hello World!", "\0", 20);
       char *expected4 = "Hello World!";
       result = strcmp(result4, expected4) == 0;
       printf("Test 4: ft_strnstr(\"Hello World!\", \"\\0\", 20) - Result: %s, Expected: %s - %s\n",
              result4, expected4,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 5: char is \0
        printf("%s", RED);
       char *result5 = ft_strnstr("", "World", 8);
       result = result5 == NULL;
       printf("Test 5: ft_strnstr(\"\", \"World\", 8) - Result: %s, Expected: NULL - %s\n",
              result5,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 6:
       printf("%s", RED);
       char *result6 = ft_strnstr(NULL, "fake", 0);
       result = result6 == NULL;
       printf("Test 5: ft_strnstr(\"\", \"World\", 8) - Result: %s, Expected: NULL - %s\n",
              result6,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 7: Segmentation fault
       printf("%s", RED);
       char *result7 = ft_strnstr("Hello World!", NULL, 8);
       result = result7 == NULL;
       printf("Test 7: ft_strnstr(\"Hello World!\", NULL, 8) - Result: %s, Expected: NULL - %s\n",
              result7,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 8: Segmentation fault
       printf("%s", RED);
       char *result8 = ft_strnstr(NULL, NULL, 8);
       result = result8 == NULL;
       printf("Test 8: ft_strnstr(NULL, NULL, 8) - Result: %s, Expected: NULL - %s\n",
              result8,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 9: Segmentation fault
       printf("%s", RED);
       char *result9 = ft_strnstr(NULL, "Hello", 8);
       result = result9 == NULL;
       printf("Test 9: ft_strnstr(NULL, \"Hello\", 8) - Result: %s, Expected: NULL - %s\n",
              result9,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
              
}
