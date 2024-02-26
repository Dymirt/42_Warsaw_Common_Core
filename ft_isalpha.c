/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:44:39 by dkolida           #+#    #+#             */
/*   Updated: 2024/02/26 18:56:11 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_islower(int c);
static int ft_isupper(int c);

int ft_isalpha(int c)
{
    return (ft_isupper(c)  ||  ft_islower(c));
}

static int ft_islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

static int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}
