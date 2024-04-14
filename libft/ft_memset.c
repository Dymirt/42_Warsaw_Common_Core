/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:14:59 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/16 18:05:46 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int value, int n)
{
	char	*ptr;

	ptr = s;
	while (n)
	{
		*ptr = value;
		ptr++;
		n--;
	}
	return (s);
}