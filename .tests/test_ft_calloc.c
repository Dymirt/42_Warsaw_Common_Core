#include "libft.h"
#include <string.h>

void test_ft_calloc();

int main()
{
	test_ft_calloc();
	return 0;
}

void test_ft_calloc()
{
    // Test case 1: Allocating and initializing memory for integers
    size_t size1 = 5;
    size_t elem_size1 = sizeof(int);
    void *result1 = ft_calloc(size1, elem_size1);
    void *expected1 = calloc(size1, elem_size1);
    int result = memcmp(result1, expected1, size1 * elem_size1) == 0;
    printf("Test 1: ft_calloc(5, sizeof(int)) - Result: %s\n",
        result ? GREEN "Pass" NORMAL : RED "Fail" NORMAL);
    free(result1);
    free(expected1);

    // Test case 2: Allocating and initializing memory for characters
    size_t size2 = 8;
    size_t elem_size2 = sizeof(char);
    char *result2 = ft_calloc(size2, elem_size2);
    char *expected2 = calloc(size2, elem_size2);
    result = memcmp(result2, expected2, size2 * elem_size2) == 0;
    printf("Test 2: ft_calloc(8, sizeof(char)) - Result: %s\n",
        result ? GREEN "Pass" NORMAL : RED "Fail" NORMAL);
    free(result2);
    free(expected2);

    // Test case 3: Allocating and initializing memory for a custom struct
    typedef struct {
        int value;
        char symbol;
    } CustomStruct;

    size_t size3 = 3;
    size_t elem_size3 = sizeof(CustomStruct);
    CustomStruct *result3 = ft_calloc(size3, elem_size3);
    CustomStruct *expected3 = calloc(size3, elem_size3);
    result = memcmp(result3, expected3, size3 * elem_size3) == 0;
    printf("Test 2: ft_calloc(3, sizeof(CustomStruct)) - Result: %s\n",
        result ? GREEN "Pass" NORMAL : RED "Fail" NORMAL);
    free(result3);
    free(expected3);
}
