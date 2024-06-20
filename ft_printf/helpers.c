/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:17:32 by dmytrokolid       #+#    #+#             */
/*   Updated: 2024/06/20 20:25:43 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_itoa_wrapper(long long n)
{
    return ft_itoa((int)n);
}

char *ft_utoa_wrapper(long long n)
{
    return ft_utoa((unsigned int)n);
}

char *ft_ctoa_wrapper(long long n)
{
    return ft_ctoa((unsigned int)n);
}

char *ft_utob16_wrapper(long long n)
{
    return ft_utob16((unsigned int)n);
}

char *ft_utob16u_wrapper(long long n)
{
    return ft_utob16u((unsigned int)n);
}
