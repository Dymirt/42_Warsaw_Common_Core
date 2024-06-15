/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:09:23 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/10 19:07:37 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int ft_sorted_desc(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
