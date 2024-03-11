/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:05:53 by dkolida           #+#    #+#             */
/*   Updated: 2024/03/11 20:39:49 by dmytrokolid      ###   ########.fr       */
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
		printf("%sOK ", GREEN);
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
		printf("%sOK ", GREEN);
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
		printf("%sOK ", GREEN);
	}

	if(ft_memcpy(NULL, "segfaulter tu dois", 17) != 0)
	{
		printf("%sKO %p ", RED, ft_memcpy(NULL, "segfaulter tu dois", 17));
	}
	else
	{
		printf("%sOK ", GREEN);
	}

	printf("%s\n", NORMAL);
}
