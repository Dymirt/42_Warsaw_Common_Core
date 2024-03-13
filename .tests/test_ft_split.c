#include "libft.h"
#include <string.h>

void test_ft_split();
static int  arrcmp(char **arr1, char **arr2);
static void free_array(char **arr);
static void print_arr(char **arr);

int main() {
	test_ft_split();
}

void test_ft_split()
{
    // Test case 1: Multiple words, multiple separators
    char *str1 = ",Hello,World,,This,is,a,,,,,,test,";
    char charset1 = ',';
    char **result1 = ft_split(str1, charset1);
    char *expected1[] = {"Hello", "World", "This", "is", "a", "test", 0};
    int result = arrcmp(result1, expected1) == 0;
    printf("Test 1: ft_split(\",Hello,World,,This,is,a,,,,,,test,\", ',') - Result: {");
    print_arr(result1);
    printf("NULL}, Expected: {");
    print_arr(expected1);
    printf("NULL} %s\n", result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free_array(result1);

    // Test case 2: Multiple words, single separator
    char *str2 = "    I   Love You  ";
    char charset2 = ' ';
    char **result2 = ft_split(str2, charset2);
    char *expected2[] = {"I", "Love", "You", 0};
    result = arrcmp(result2, expected2) == 0;
    printf("Test 2: ft_split(\"    I   Love You  \", ' ') - Result: {");
    print_arr(result2);
    printf("NULL}, Expected: {");
    print_arr(expected2);
    printf("NULL} %s\n", result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free_array(result2);

    // Test case 3: Single word
    char *str3 = "42Warsaw";
    char charset3 = '-';
    char **result3 = ft_split(str3, charset3);
    char *expected3[] = {"42Warsaw", 0};
    result = arrcmp(result3, expected3) == 0;
    printf("Test 3: ft_split(\"42Warsaw\", '-') - Result: {");
    print_arr(result3);
    printf("NULL}, Expected: {");
    print_arr(expected3);
    printf("NULL} %s\n", result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free_array(result3);

	// Test case 4: Empty string
    char *str4 = "";
    char charset4 = '.';
    char **result4 = ft_split(str4, charset4);
    char *expected4[] = {0};
    result = arrcmp(result4, expected4) == 0;
    printf("Test 4: ft_split(\"\", '.') - Result: {");
    print_arr(result4);
    printf("NULL}, Expected: {");
    print_arr(expected4);
    printf("NULL} %s\n", result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    free_array(result4);
}

static int  arrcmp(char **arr1, char **arr2)
{
    int i = 0;
    while (arr1[i] && arr2[i])
    {
        if (!arr1[i] || !arr2[i] || strcmp(arr1[i], arr2[i]) != 0)
            return (-1);
        i++;
    }
    return (0);
}

static void free_array(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

static void print_arr(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        printf("%s, ", arr[i]);
        i++;
    }
}
