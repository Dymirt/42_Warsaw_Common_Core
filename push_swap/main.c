/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:00:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/20 18:00:15 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct int_arr	*stack_a;
	struct int_arr	*stack_b;

	stack_a = init_stak_a(argc, argv);
	stack_b = init_stak_b(stack_a);
	while (!nearly_sorted(stack_a))
	{
		if (check_swap(stack_a) && stack_a->size == 3)
			swap_head(stack_a->array, "sa");
		else if (stack_b->size == 0)
		{
			while (stack_b->size < 2)
				push(stack_a, stack_b, "pb");
		}
		else
			push_to_b(stack_a, stack_b);
	}
	push_to_a(stack_a, stack_b);
	rotate_to(stack_a, min_value(stack_a), "ra", "rra");
	free(stack_a->array);
	free(stack_a);
	free(stack_b->array);
	free(stack_b);
}
