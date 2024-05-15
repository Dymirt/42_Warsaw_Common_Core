#include "libft.h"

#include <ctype.h>

int main(){
	if (!!ft_isprint(1) != !!isprint(1))
	{
		printf("BAD case 1\n");
		return 1;
	}

	if (!!ft_isprint('a') != !!isprint('a'))
	{
		printf("BAD case 2\n");
		return 1;
	}

	if (!!ft_isprint(127) != !!isprint(127))
	{
		printf("BAD case 3\n");
		return 1;
	}

	printf("%sOK\n", GREEN);
	printf("%s", NORMAL);
	return 0;
}
