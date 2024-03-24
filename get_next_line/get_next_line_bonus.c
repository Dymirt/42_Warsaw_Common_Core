/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:45:37 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/24 21:02:52 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_read(int fd, char **str);
static char	*ft_get_line(char **str);
static int	save_to_static(char **str, int i);

char	*get_next_line(int fd)
{
	static char	*str[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str[fd])
	{
		str[fd] = ft_strdup("");
		if (!str[fd])
			return (NULL);
	}
	if (ft_read(fd, &str[fd]) <= 0)
	{
		free(str[fd]);
		return (NULL);
	}
	return (ft_get_line(&str[fd]));
}

static int	ft_read(int fd, char **str)
{
	char		*line;
	int			bytes_read;
	char		*tmp;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	bytes_read = 1;
	while (!ft_strchr(*str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		line[bytes_read] = '\0';
		tmp = ft_strjoin(*str, line);
		if (!tmp)
			return (0);
		free(*str);
		*str = tmp;
	}
	free(line);
	return (bytes_read);
}

static char	*ft_get_line(char **str)
{
	char	*line;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\0')
	{
		line = ft_strdup(*str);
		if (!line)
			return (NULL);
		free(*str);
		*str = NULL;
		return (line);
	}
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *str, i + 2);
	if (!save_to_static(&(*str), i))
		return (NULL);
	return (line);
}

static int	save_to_static(char **str, int i)
{
	char	*tmp;

	tmp = ft_strdup(&((*str)[i + 1]));
	if (!tmp)
		return (0);
	free(*str);
	*str = tmp;
	return (1);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;

	s_len = ft_strlen(s);
	dest = (char *)malloc((s_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, (char *)s, s_len + 1);
	return (dest);
}
