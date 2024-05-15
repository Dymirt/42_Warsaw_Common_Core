/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:11 by dkolida           #+#    #+#             */
/*   Updated: 2024/05/15 23:51:57 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

// swap.c
void	swap_head(int *stack, char *str);
void	ss(int *stack_a, int *stack_b);
// rotate.c
void rotate(int *stack_a, int size, char *str);
void rr(int *stack_a, int *stack_b, int size_a, int size_b);
int check_for_ra(int *stack_a, int size);
int check_for_rb(int *stack, int size);

int		ft_printf(const char *format, ...);
char	*ft_utoa(unsigned int n);
char	*ft_memjoin(char *s1, char *s2, size_t len1, size_t len2);
char	*ft_utoa_base(uintptr_t nbr, char *base);
char	*ft_ctoa(unsigned int c);
char	*ft_utob16(unsigned int n);
char	*ft_utob16u(unsigned int n);
int		ft_swap_and_free(char **str1, char **str2);
void	ft_printf_handle_s(char *va_sting, size_t *res, char **p_str);
void	ft_printf_handle_p(uintptr_t nbr, size_t *res, char **p_str);
void	printf_join(char **p_str, char *str, size_t *res, size_t str_len);




#endif
