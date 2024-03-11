#include "libft.h"

static int ft_nbrlen(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	neg = 0;
	len = ft_nbrlen(n);
	if (n < 0)
	{
		neg = 1;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) * (1 - 2 * neg) + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

static int ft_nbrlen(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}
