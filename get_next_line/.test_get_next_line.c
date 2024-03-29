/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:45:43 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/24 18:40:57 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int main()
{
	int		fd_star_wars;
	char	*line;


	fd_star_wars = open("star_wars.txt", O_RDONLY);
	while ((line = get_next_line(fd_star_wars)))
	{
		printf("%s", line);
		free(line);
	}
	line = get_next_line(42);
	printf("%s", line);
	free(line);
	return (0);
}
