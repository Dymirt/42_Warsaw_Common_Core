
#include "libft.h"

#include <assert.h>
#include <string.h>

int main() {
    int i;


    char test_cases[][20] = {"", "Hello", "Hello, world!"};

    for (i = 0; i < 3; i++)
        if (ft_strlen(test_cases[i]) != strlen(test_cases[i])){
            printf("BAD\n");
            return 1;
        }
    printf("OK\n");
    return 0;
}