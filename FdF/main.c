/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:10:33 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/04 00:09:43 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
#include <fcntl.h>


int main(int argc, char **argv)
{
	char	*line;
	int fd;

	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		ft_printf("%s\n", line);
		free(line);
	}

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return (0);
}
