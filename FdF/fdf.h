/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:09:30 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 20:05:01 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define ESC_KEY_MAC 53
# define SCALE_P 24
# define SCALE_M 27
# define SIN_P 30
# define SIN_M 33

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
	float			x;
	float			y;
	unsigned int	color;
}	t_dot;

typedef struct s_tmp
{
	int		row;
	int		col;
}	t_tmp;

typedef struct s_map
{
	t_data	img;
	t_dot	***map3d;
	char	***map2d;
	float	scale;
	int		width;
	int		height;
	float	sin_angle;
	float	cos_angle;
	float	min_x;
	float	min_y;
	float	max_x;
	float	max_y;
	float	degrees_rotate;
	float	moves_x;
	float	moves_y;
	int		on_start;
	t_tmp	*tmp;
}	t_map;
typedef struct s_fdf
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map_data;
}	t_fdf;

//src/for_each_mod_functions.c
void	to_positive(t_map *map, t_dot *dot);
void	scale_dot(t_map *map, t_dot *dot);
void	move_dot(t_map *map, t_dot *dot);
void	draw_lines(t_map *map, t_dot *dot);

//src/for_each_functions.c
void	for_each_t_dot(t_map *map, void (*f)(t_map *, t_dot *));

// helpers_3d.c
void	scale_3d_map(t_map *map_data);
void	update_map_min_max(t_map *map);
void	rotate_map(t_map *map);
void	center_map_to_screen(t_map *map);
void	transate_to_positive(t_map *map);
void	rotate_point(t_dot *dot, float degrees);
void	apply_moves(t_map *map);

// ft_realloc.c
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

// ft_atoi_base.c
int		ft_atoi_base(char *str, char *base);

//map_setup.c
t_dot	***malloc_3d_fdf_map(int map_width, int map_height);
void	load_map(char *file_name, char ****map, int *width, int *height);
void	free_map_data(t_map *map_data);

//src/img.c
void	drow_img(t_fdf *fdf);
void	draw_line(t_dot *start, t_dot *end, t_data img);

// src/color.c
int		get_color(char *color_str);

// src/isometric.c
void	create_3d_map(t_map *map);

#endif
