/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:11:44 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/02 19:50:53 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_memcmp(const void *s1, const void *s2, int n)
{
	unsigned	char *prts1 = (unsigned char *)s1;
	unsigned char *prts2 = (unsigned char *)s2;
	
	int	i;

	i = 0;
	while (i < n)
	{
		if (prts1[i] != prts2[i])
			return (prts1[i] - prts2[i]);
		i++;
	}
	return (0);
	
}
