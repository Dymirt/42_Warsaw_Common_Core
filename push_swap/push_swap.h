/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:11 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 18:13:36 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

//valid_input.c
t_int_arr	*valid_input(int argc, char **argv);

// swap.c
void		swap_head(int *stack, char *str);
void		ss(int *stack_a, int *stack_b);
// rotate.c
void		rotate(t_int_arr *stack_a, char *str);
void		rr(t_int_arr *stack_a, t_int_arr *stack_b);
int			check_for_ra(t_int_arr *stack);
int			check_for_rb(t_int_arr *stack);
// Reverse rotate at rotate.c
void		reverse_rotate(t_int_arr *stack, char *str);
void		rrr(t_int_arr *stack_a, t_int_arr *stack_b);
int			check_for_rra(t_int_arr *stack);
int			check_for_rrb(t_int_arr *stack);
// push.c
void		push(t_int_arr *stack_a, t_int_arr *stack_b, char *str);

int			ft_printf(const char *format, ...);
char		*ft_utoa(unsigned int n);
char		*ft_memjoin(char *s1, char *s2, size_t len1, size_t len2);
char		*ft_utoa_base(uintptr_t nbr, char *base);
char		*ft_ctoa(unsigned int c);
char		*ft_utob16(unsigned int n);
char		*ft_utob16u(unsigned int n);
int			ft_swap_and_free(char **str1, char **str2);
void		ft_printf_handle_s(char *va_sting, size_t *res, char **p_str);
void		ft_printf_handle_p(uintptr_t nbr, size_t *res, char **p_str);
void		printf_join(char **p_str, char *str, size_t *res, size_t str_len);

#endif
