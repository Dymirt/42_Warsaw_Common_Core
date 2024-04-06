# include "ft_printf.h"

int test_ft_printf(void)
{
	char *str = "Hello, %x%% %s%c %u";
	unsigned int max_uint = 4294967295;
	int result = ft_printf(str, 42, "World", '!', max_uint);
	return (result);
}

int main(void)
{
	int result = test_ft_printf();
	printf("\n%x\n", result);
}
