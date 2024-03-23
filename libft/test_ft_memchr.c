#include "libft.h"
#include <string.h>

void test_ft_memchr();

int main() {
	test_ft_memchr();
	return 0;
}


void test_ft_memchr()
{
    // Test case 1: finding 'e' in a non-empty buffer
    char buffer1[10] = "Hello";

    void *result1 = ft_memchr(buffer1, 'e', 3);
    void *expected1 = memchr(buffer1, 'e', 3);
    int result = strcmp((char *) result1, (char *) expected1) == 0;
    printf("Test 1: ft_memchr(\"Hello\", 'e', 5) - Result: %s, Expected: %s - %s\n",
        (char *) result1, (char *) expected1, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 2: finding 't' in an entire buffer
    char buffer2[5] = "Test";

    void* result2 = ft_memchr(buffer2, 't', sizeof(buffer2));
    void* expected2 = memchr(buffer2, 't', sizeof(buffer2));
    result = strcmp((char *) result2, (char *) expected2) == 0;
    printf("Test 2: ft_memchr(\"Test\", 't', sizeof(\"Test\")) - Result: %s, Expected: %s - %s\n",
        (char *) result2,(char *) expected2, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 3: finding 'i' in part of a buffer
    char buffer3[9] = "Love You";

    void* result3 = ft_memchr(buffer3, ' ', 5);
    void* expected3 = memchr(buffer3, ' ', 5);
    result = strcmp((char *) result3, (char *) expected3) == 0;
    printf("Test 3: ft_memchr(\"Love You\" + 2, ' ', 5) - Result: %s, Expected: %s - %s\n",
        (char *) result3, (char *) expected3, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 4: finding 'x' in a buffer where it doesn't exist
    void* result4 = ft_memchr(buffer3, 'x', sizeof(buffer3));
    void* expected4 = memchr(buffer3, 'x', sizeof(buffer3));
    result = result4 == expected4;
    printf("Test 4: ft_memchr(\"Love You\", 'x', sizeof(\"Love You\")) - Result: %s, Expected: %s - %s\n",
        (char *) result4, (char *) expected4, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
}
