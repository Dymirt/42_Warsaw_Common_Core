/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:11:44 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/02 19:19:18 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_memcmp(const void *s1, const void *s2, int n)
{
	char *prts1 = (char *)s1;
	char *prts2 = (char *)s2;
	
	int	i;

	i = 0;
	while (i < n && (prts1[i] != '\0' || prts2[i] != '\0'))
	{
		if (prts1[i] != prts2[i])
			return (prts1[i] - prts2[i]);
		i++;
	}
	return (0);
	
}
