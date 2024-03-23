#include "libft.h"
#include <string.h>

void test_ft_memmove();

int main() {
	test_ft_memmove();
}

void test_ft_memmove()
{
    char source1[10] = "Hello";
    char result1[10] = "World";
    char expected1[10] = "World";

    // Test case 1: moving from a non-empty source to a non-empty destination
    ft_memmove(result1 + 1, source1, 5);
    memmove(expected1 + 1, source1, 5);
    int result = memcmp(result1, expected1, sizeof(result1)) == 0;
    printf("Test 1: ft_memmove(destination1 + 1, source1, 5) - Result: %s, Expected: %s - %s\n",
    	result1, expected1,
    	result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    char source2[5] = "Test";
    char result2[5] = "";
    char expected2[5] = "";

    // Test case 2: moving from a non-empty source to an empty destination
    ft_memmove(result2, source2, sizeof(source2));
    memmove(expected2, source2, sizeof(source2));
    result = memcmp(result2, expected2, sizeof(result2)) == 0;
    printf("Test 2: ft_memmove(\"\", \"Test\", sizeof(\"Test\")) - Result: %s, Expected: %s - %s\n",
    result2, expected2,
    result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

    // Test case 3: overlapping move from a non-empty source to part of a destination
    char source3[9] = "Love You";
    char result3[8] = "XXXXXXX";
    char expected3[8] = "XXXXXXX";

    ft_memmove(result3 + 3, source3, 3);
    memmove(expected3 + 3, source3, 3);
    result = memcmp(result3, expected3, sizeof(result3)) == 0;
    printf("Test 3: ft_memmove(\"XXXXXXX\" + 3, \"Love You\", 3) - Result: %s, Expected: %s - %s\n",
    	result3, expected3,
    	result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);

}
