/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:55:13 by dkolida           #+#    #+#             */
/*   Updated: 2024/02/28 20:15:35 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strdup(char *src);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void 			*ft_memset(void *s, int c, size_t n);

#endif
