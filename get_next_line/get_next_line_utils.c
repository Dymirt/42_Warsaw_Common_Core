#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, len1 + 1);
	ft_strlcat(joined, s2, len1 + len2 + 1);
	return (joined);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstptr;

	dstptr = (unsigned char *)dst;
	if (dst == 0 && src == 0)
	{
		return (dst);
	}
	while (n > 0)
	{
		*dstptr = *(unsigned char *)src;
		dstptr++;
		src++;
		n--;
	}
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_lenth;
	size_t			src_lenth;
	size_t			i;

	if (dst == 0 && dstsize == 0)
		return (ft_strlen(src));
	dst_lenth = ft_strlen(dst);
	src_lenth = ft_strlen(src);
	i = dst_lenth;
	if (dstsize == 0 || dstsize <= dst_lenth)
		return (src_lenth + dstsize);
	while (i < dstsize - 1 && *src != '\0')
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (dst_lenth + src_lenth);
}
