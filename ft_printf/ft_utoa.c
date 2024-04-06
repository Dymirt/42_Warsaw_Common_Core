#include "ft_printf.h"

static	size_t	ft_unbrlen(unsigned int n);

char	*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	len;

	len = ft_unbrlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	printf("ft_utoa: %s\n", str);
	return (str);
}

static size_t	ft_unbrlen(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}
