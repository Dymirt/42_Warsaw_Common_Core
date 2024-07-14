/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:51:36 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/14 15:25:09 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	**split_to_pairs(char *str);

int	create_trgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	get_color(char *color_str)
{
	int		colors_int[4];
	char	**colors_str;
	int		color;
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
	color = create_trgb(colors_int[0], colors_int[1], colors_int[2]);
	ft_free_split(colors_str);
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
