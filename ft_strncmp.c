/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:28:07 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/02 19:43:33 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	
	unsigned char *ptrs1 = (unsigned char *)s1;
	unsigned char *ptrs2 = (unsigned char *)s2;

	i = 0;
	while (i < n && (ptrs1[i] != '\0' || ptrs2[i] != '\0'))
	{
		if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
		i++;
	}
	return (0);
}
