#include "libft.h"
#include <string.h>

static void a_to_X(unsigned int i, char *c);
void test_ft_striteri();

int main() {
	test_ft_striteri();
}

void test_ft_striteri()
{
       // Test case 1
       char result1[] = "aaaaaabbbbaa!";
       char *expected1 = "XaXaXabbbbXa!";
       ft_striteri(result1, &a_to_X);
       int result = strcmp(result1, expected1) == 0;
       printf("Test 1: ft_striteri(\"aaaaaabbbbaa\", &a_to_X) - Result: %s, Expected: %s - %s\n",
              result1, expected1,
              result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

       // Test case 2
       char result2[] = "";
       ft_striteri(result2, &a_to_X);
       result = strcmp(result2, "") == 0;
       printf("Test 2: ft_striteri(\"\", &a_to_X) - Result: %s, Expected: \"\" - %s\n",
              result2, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}

static void a_to_X(unsigned int i, char *c)
{
       if (*c == 'a' && i % 2 == 0)
              *c = 'X';
}
