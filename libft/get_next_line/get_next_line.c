/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:45:37 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/03 23:03:44 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
