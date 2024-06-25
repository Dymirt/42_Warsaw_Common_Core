
#include "libft.h"

#include <assert.h>
#include <string.h>
#include <ctype.h>

int main() {

    if (!ft_isdigit(1) && isdigit(1))
    {
        ft_printf("BAD case 1\n");
        return 1;
    }

    if (ft_isdigit('a') && isdigit('a'))
    {
        ft_printf("BAD case 2\n");
        return 1;
    }

    if (!ft_isdigit('1') && isdigit('1'))
    {
        ft_printf("BAD case 3\n");
        return 1;
    }

    ft_printf("%sOK\n", GREEN);
    ft_printf("%s", NORMAL);
    return 0;
}
