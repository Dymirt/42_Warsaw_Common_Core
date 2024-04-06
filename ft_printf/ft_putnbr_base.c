#include "ft_printf.h"

void	ft_putnbr_base_recursive(int nbr, char *base, int base_length , char *base_ptr)
{
	if (nbr == -2147483648)
	{
		base_ptr = ft_strjoin(base_ptr, "-");
		ft_putnbr_base_recursive(-(nbr / base_length), base, base_length, base_ptr);
		base_ptr = ft_strjoin(base_ptr, &base[-(nbr % base_length)]);
		return ;
	}
	if (nbr < 0)
	{
		base_ptr = ft_strjoin(base_ptr, "-");
		nbr = -nbr;
	}
	if (nbr >= base_length)
	{
		ft_putnbr_base_recursive(nbr / base_length, base, base_length, base_ptr);
	}
	base_ptr = ft_strjoin(base_ptr, ft_substr(base, nbr % base_length, 1 ));
}

char *ft_putnbr_base(int nbr, char *base)
{
	int	base_length;
	char	*base_ptr;

	base_length = ft_strlen(base);

	base_ptr = calloc(1, sizeof(char));

	ft_putnbr_base_recursive(nbr, base, base_length, base_ptr);
	return (base_ptr);
}
