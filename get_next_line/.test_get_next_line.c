#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int main()
{
	int		fd_star_wars;
	char	*line;


	fd_star_wars = open("star_wars.txt", O_RDONLY);

	line = get_next_line(fd_star_wars);
	printf("%s", line);
	free(line);
	line = get_next_line(fd_star_wars);
	printf("%s", line);
	free(line);
	line = get_next_line(fd_star_wars);
	printf("%s", line);
	free(line);
	line = get_next_line(fd_star_wars);
	printf("%s", line);
	free(line);
	line = get_next_line(fd_star_wars);
	printf("%s", line);
	free(line);
	return (0);
}
