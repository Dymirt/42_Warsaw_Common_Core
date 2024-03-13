#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	size_t len;
	size_t start;
	size_t end;

	if (!s1 || !set)
		return (NULL);

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;

	end = ft_strlen(s1);

	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;

	len = end - start;
	return (ft_substr(s1, start, len));
}
