#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*tmp;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	if (!str)
		str = ft_strdup("");
	while (!ft_strchr(str, '\n') && (ret = read(fd, line, BUFFER_SIZE)) > 0)
	{
		line[ret] = '\0';
		tmp = ft_strjoin(str, line);
		free(str);
		str = tmp;
	}
	free(line);
	if (ret <= 0)
		return (NULL);
	return (ft_get_line(&str));
}

char *ft_get_line(char **str)
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
		free(*str);
		*str = NULL;
		return (line);
	}
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *str, i + 2);
	tmp = ft_strdup(&((*str)[i + 1]));
	free(*str);
	*str = tmp;
	return (line);
}
