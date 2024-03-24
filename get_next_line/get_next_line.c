#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*tmp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		str = ft_strdup("");
	if (!line || !str)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		line[bytes_read] = '\0';
		tmp = ft_strjoin(str, line);
		if (!tmp)
			return (NULL);
		free(str);
		str = tmp;
	}
	free(line);
	if (bytes_read <= 0)
		return (NULL);
	return (ft_get_line(&str));
}



char	*ft_get_line(char **str)
{
	char	*line;
	char	*tmp;
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
	tmp = ft_strdup(&((*str)[i + 1]));
	if (!tmp)
		return (NULL);
	free(*str);
	*str = tmp;
	return (line);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	s_len;

	s_len = ft_strlen(s);
	dest = (char *)malloc((s_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	return (ft_memcpy(dest, (char *)s, s_len + 1));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}

	if (c == '\0')
		return ((char *)s);

	return (0);
}
