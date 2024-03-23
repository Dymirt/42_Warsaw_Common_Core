#include "libft.h"
#include <string.h>

void test_ft_strlcat();

int main() {
	test_ft_strlcat();
	return 0;
}

void test_ft_strlcat()
{
       // Test case 1: Concatenate strings within the available size
       char dest1[15] = "Hello";
       const char *src1 = " World";
       size_t result1 = ft_strlcat(dest1, src1, sizeof(dest1));
       int result = result1 == 11 && !strcmp(dest1, "Hello World");
       printf("Test 1: ft_strlcat(\"Hello\", \" World\", 15) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest1, result1, "Hello World", 11,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: Concatenate strings where destination buffer is too small
       char dest2[8] = "Hello";
       const char *src2 = " World";
       size_t result2 = ft_strlcat(dest2, src2, 8);
       result = result2 == 11 && !strcmp(dest2, "Hello W");
       printf("Test 2: ft_strlcat(\"Hello\", \" World\", 8) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest2, result2, "Hello W", 11,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: Concatenate empty source string
       char dest3[10] = "Hello";
       const char *src3 = "";
       size_t result3 = ft_strlcat(dest3, src3, 10);
       result = result3 == 5 && !strcmp(dest3, "Hello");
       printf("Test 3: ft_strlcat(\"Hello\", \"\", 10) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest3, result3, "Hello", 5,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 4: Concatenate to an empty destination string
       char dest4[15] = "";
       const char *src4 = "Hello World";
       size_t result4 = ft_strlcat(dest4, src4, sizeof(dest4));
       result = result4 == 11 && !strcmp(dest4, "Hello World");
       printf("Test 4: ft_strlcat(\"\", \"Hello World\", 15) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest4, result4, "Hello World", 11,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 5: Size lower than dest length
       char dest5[15] = "Hello";
       const char *src5 = " World";
       size_t result5 = ft_strlcat(dest5, src5, 3);
       result = result5 == 9 && !strcmp(dest5, "Hello");
       printf("Test 5: ft_strlcat(\"Hello\", \" World\", 3) - Result: %s, %zu, Expected: %s, %d - %s\n",
              dest5, result5, "Hello", 9,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
