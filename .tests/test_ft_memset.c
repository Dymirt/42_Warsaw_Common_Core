#include "libft.h"
#include <string.h>

int main() {
	char test_cases[] = "Hello 2 World";
	ft_memset(test_cases, '*', 5);
	if (ft_memset(test_cases, '*', 5) != memset(test_cases, '*', 5))
		printf("%sKO", RED);
	if (ft_memset(test_cases, '*', 0) != memset(test_cases, '*', 0))
		printf("%sKO", RED);
	printf("%sOK", GEEN);
	printf("%s\n", NORMAL);
	return 0;
}
