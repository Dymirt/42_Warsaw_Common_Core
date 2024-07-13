/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:51:36 by dkolida           #+#    #+#             */
/*   Updated: 2024/07/13 16:29:40 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	**split_to_pairs(char *str);
void	str_toupper(char *str);

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(char *color_str)
{
	int		colors_int[3];
	char	**colors_str;
	int		color;
	int		i;
	int		j;

	ft_str_toupper(color_str);
	ft_printf("color_str: %s\n", color_str);
	colors_str = split_to_pairs(color_str + 2);
	i = 0;
	j = 0;
	while (colors_str[j])
	{
		colors_int[i] = ft_atoi_base(colors_str[j], "0123456789ABCDEF");
		j++;
		i++;
	}
	color = create_trgb(0, colors_int[0], colors_int[1], colors_int[2]);
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
