#include "libft.h"

#include <ctype.h>

int main(){
	if (!!ft_isprint(1) != !!isprint(1))
	{
		ft_printf("BAD case 1\n");
		return 1;
	}

	if (!!ft_isprint('a') != !!isprint('a'))
	{
		ft_printf("BAD case 2\n");
		return 1;
	}

	if (!!ft_isprint(127) != !!isprint(127))
	{
		ft_printf("BAD case 3\n");
		return 1;
	}

	ft_printf("%sOK\n", GREEN);
	ft_printf("%s", NORMAL);
	return 0;
}
