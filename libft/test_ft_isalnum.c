
#include "libft.h"

#include <assert.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i;


    char test_cases[] = "Hello 2 World";

    for (i = 0; i < 14; i++)
	{
        if (!!ft_isalnum(test_cases[i]) == !!isalnum(test_cases[i]))
			printf("%sOK[%d] ", GREEN, i);
		else
			printf("%sKO[%d] ", RED, i);
	}
	printf("%s\n", NORMAL);

    return 0;
}
