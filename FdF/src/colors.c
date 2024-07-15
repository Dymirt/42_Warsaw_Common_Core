/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:51:36 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/15 23:36:31 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	**split_to_pairs(char *str);

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_color	*get_color(char *color_str)
{
	int		colors_int[4];
	char	**colors_str;
	t_color	*color;
	int		i;
	int		j;

	ft_str_toupper(color_str);
	colors_str = split_to_pairs(color_str + 2);
	i = 0;
	j = 0;
	while (colors_str[j])
	{
		colors_int[i] = ft_atoi_base(colors_str[j], "0123456789ABCDEF");
		j++;
		i++;
	}
	ft_free_split(colors_str);
	color = malloc(sizeof(t_color));
	color->r = colors_int[0];
	color->g = colors_int[1];
	color->b = colors_int[2];
	return (color);
}

char	**split_to_pairs(char *str)
{
	char	**pairs;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	pairs = (char **)malloc(sizeof(char *) * (ft_strlen(str) / 2 + 1));
	while (str[i] != '\0')
	{
		tmp = ft_substr(str, i, 2);
		if (ft_strlen(tmp) == 2)
		{
			pairs[j] = tmp;
			j++;
		}
		else
		{
			free(tmp);
		}
		i += 2;
	}
	pairs[j] = NULL;
	return (pairs);
}
