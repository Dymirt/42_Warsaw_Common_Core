/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:09:30 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/10 17:05:41 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
#include <fcntl.h>


# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_dot
{
	int x;
	int y;
	int color;
}	t_dot;

typedef struct s_map
{
	t_dot	***map3d;
	char	***map2d;
	int		scale;
	int		width;
	int		height;
}	t_map;

// helpers_3d.c
int		isometric_x (int x, int y, float rotation);
int		isometric_y (int x, int y, int z, float rotation);
void	scale_3d_map(t_map *map_data);

// ft_realloc.c
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

// ft_atoi_base.c
int ft_atoi_base(char *str, char *base);


//map_setup.c
t_dot	***allocate_map(int map_width, int map_height);
void	translate_map_3d(char	***map, t_dot ***coordinates, int map_width, int map_height);
void	load_map(char *file_name, char ****map, int *map_width, int *map_height);
void	free_map_data (t_map *map_data);




#endif
