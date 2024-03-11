#include "libft.h"
#include <string.h>

void test_ft_strlcpy();

int main() {
	test_ft_strlcpy();
}

void test_ft_strlcpy()
{
       // Test case 1: Copying a string within the buffer size
       char dest1[10] = "Hello";
       const char *src1 = "World";
       size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1));
       int result = result1 == 5 && !strcmp(dest1, "World");
       printf("Test 1: ft_strlcpy(\"Hello\", \"World\", 10) - Result: %s, %zu, Expected: World, 5 - %s\n",
              dest1, result1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: Copying an empty string
       char dest2[10] = "Hello";
       const char *src2 = "";
       size_t result2 = ft_strlcpy(dest2, src2, sizeof(dest2));
       result = result2 == 0 && !strcmp(dest2, "");
       printf("Test 2: ft_strlcpy(\"Hello\", \"\", 10) - Result: %s, %zu, Expected: \"\", 0 - %s\n",
              dest2, result2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 3: Buffer size is less than the source string
       char dest3[5] = "Hello";
       const char *src3 = "World";
       size_t result3 = ft_strlcpy(dest3, src3, 4);
       result = result3 == 5 && !strcmp(dest3, "Wor");
       printf("Test 3: ft_strlcpy(\"Hello\", \"World\", 5) - Result: %s, %zu, Expected: Wor, 5 - %s\n",
              dest3, result3,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
