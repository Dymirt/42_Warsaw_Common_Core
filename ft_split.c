#include "libft.h"

char **ft_split(char const *s, char c)
{
	char **split;
	size_t i;
	size_t j;
	size_t substring_lenth;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (!split)
		return (NULL);


	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			substring_lenth = 0;
			while (s[i + substring_lenth] && s[i + substring_lenth] != c)
				substring_lenth++;
			split[j] = ft_substr(s, i, substring_lenth);
			i += substring_lenth;
			j++;
		}
	}

	split[j] = NULL;
	return (split);
}

