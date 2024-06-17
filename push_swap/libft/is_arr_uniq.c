/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arr_uniq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:21:49 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/17 21:39:58 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_arr_uniq(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[j] == array[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
