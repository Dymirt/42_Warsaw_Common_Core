#include "libft.h"
#include <string.h>

void test_ft_strmapi();
static char caesarEncrypt(unsigned int i, char c);

int main() {
	test_ft_strmapi();
}

void test_ft_strmapi()
{
       // Test case 1: Basic Test
       char input1[] = "Hdjik!";
       char expected1[] = "Hello!";
       char *result1 = ft_strmapi(input1, &caesarEncrypt);
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_strmapi(\"Hdjik!\", &caesarEncrypt) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2: Empty String
       char input2[] = "";
       char *result2 = ft_strmapi(input2, &caesarEncrypt);
       result = strcmp(result2, "") == 0;
       printf("Test 2: ft_strmapi(\"\", &caesarEncrypt) - Result: %s, Expected: \"\" - %s\n",
              result2,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       free(result1);
       free(result2);
}

static char caesarEncrypt(unsigned int i, char c)
{
       if (c >= 'A' && c <= 'Z')
              c = (c - 'A' + i) % 26 + 'A';
       else if (c >= 'a' && c <= 'z')
              c = (c - 'a' + i) % 26 + 'a';
       return (c);
}
