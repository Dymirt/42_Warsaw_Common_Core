/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_get_next_line_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:45:43 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/24 16:23:26 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int main()
{
	int		fd_star_wars;
	char	*line;
	int fd;


	fd_star_wars = open("star_wars.txt", O_RDONLY);
	fd = open("test_bonus.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	line = get_next_line(fd_star_wars);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	close(fd);
	close(fd_star_wars);
	return (0);
}
