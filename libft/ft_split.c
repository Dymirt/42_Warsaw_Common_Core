/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:36:18 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/24 02:17:42 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*substring(char const *s, size_t i, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

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
			split[j] = substring(s, i, c);
			i += ft_strlen(split[j]);
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

static char	*substring(char const *s, size_t i, char c)
{
	size_t	substring_lenth;

	substring_lenth = 0;
	while (s[i + substring_lenth] && s[i + substring_lenth] != c)
		substring_lenth++;
	return (ft_substr(s, i, substring_lenth));
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
