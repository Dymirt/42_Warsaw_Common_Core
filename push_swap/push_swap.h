/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:53:11 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/24 01:31:59 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

//valid_input.c
t_int_arr	*valid_input(int argc, char **argv);

// swap.c
void		swap_head(int *stack, char *str);
int			check_swap(t_int_arr *stack);

// rotate.c
void		rotate(t_int_arr *stack_a, char *str);
void		rr(t_int_arr *stack_a, t_int_arr *stack_b);
void		reverse_rotate(t_int_arr *stack, char *str);
void		rrr(t_int_arr *stack_a, t_int_arr *stack_b);
void		rotate_to(t_int_arr *stack, int value, char *r, char *rr);

// push.c
void		push(t_int_arr *stack_a, t_int_arr *stack_b, char *str);
void		push_to_b(t_int_arr *stack_a, t_int_arr *stack_b);
void		push_to_a(t_int_arr *stack_a, t_int_arr *stack_b);

// t_int_arr.c
int			min_value(t_int_arr *stack);
int			max_value(t_int_arr *stack);
int			get_index(t_int_arr *s, int value);

// search.c
int			nearest_larfer_i(t_int_arr *s, int value);
int			nearest_smaller_i(t_int_arr *s, int value);
int			optimal_value_for_push(t_int_arr *stack_a, t_int_arr *stack_b);
int			moves_to_top(t_int_arr *s, int value);
int			calculate_moves(t_int_arr *a, t_int_arr *b, int i);

// init.c
t_int_arr	*init_stak_a(int argc, char **argv);
t_int_arr	*init_stak_b(t_int_arr *stack_a);

// helpers.c
int			nearly_sorted(t_int_arr *stack);

#endif
