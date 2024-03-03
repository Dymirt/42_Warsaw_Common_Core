/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:05:53 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/03 21:53:15 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int main ()
{	
	void *dest = 0;
	void *src = 0;
	
	if(ft_memcpy(dest, src, 0) != memcpy(dest, src, 0))
	{
		printf("%sKO %p, %p", RED, memcpy(dest, src, 0), ft_memcpy(dest, src, 0));
	}
	else
	{
		printf("%sOK ", GEEN);
	}
	
	dest = malloc(1);
	if (!dest)
		printf("%s Allocating mamory fail\n", RED);
	
	if(ft_memcpy(dest, src, 0) != memcpy(dest, src, 0))
	{
		printf("%sKO %p, %p", RED, memcpy(dest, src, 0), ft_memcpy(dest, src, 0));
	}
	else
	{
		printf("%sOK ", GEEN);
	}
	free(dest);

	dest = 0;
	src = malloc(1);
	if (!src)
		printf("%s Allocating mamory fail\n", RED);
	
	if(ft_memcpy(dest, src, 0) != memcpy(dest, src, 0))
	{
		printf("%sKO %p, %p", RED, memcpy(dest, src, 0), ft_memcpy(dest, src, 0));
	}
	else
	{
		printf("%sOK ", GEEN);
	}
	
	printf("%s\n", NORMAL);
}
