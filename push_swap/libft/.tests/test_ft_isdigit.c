
#include "libft.h"

#include <assert.h>
#include <string.h>
#include <ctype.h>

int main() {

    if (!ft_isdigit(1) && isdigit(1))
    {
        printf("BAD case 1\n");
        return 1;
    }

    if (ft_isdigit('a') && isdigit('a'))
    {
        printf("BAD case 2\n");
        return 1;
    }

    if (!ft_isdigit('1') && isdigit('1'))
    {
        printf("BAD case 3\n");
        return 1;
    }

    printf("%sOK\n", GREEN);
    printf("%s", NORMAL);
    return 0;
}
