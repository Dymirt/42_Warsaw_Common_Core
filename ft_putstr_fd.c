#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	size_t len;
	len = ft_strlen(s);

	if (s == NULL || fd < 0 || len == 0)
	{
		return;
    }
	write(fd, s, len);
}
