/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:09:44 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 17:36:21 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_smaller(int a, int b)
{
	return (a < b);
}

int	ft_is_larger(int a, int b)
{
	return (a > b);
}

int	ft_smallest(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_largest(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
