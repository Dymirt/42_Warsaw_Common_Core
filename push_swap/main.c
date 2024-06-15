/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:00:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/11 00:03:19 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b);
int header_fits(t_int_arr *stack);
int ft_sorted_percent(int *stack, int size);
int ft_sorted_percent_rev(int *stack, int size);
int max_value(int *stack, int size);
int min_value(int *stack, int size);
int min_value_index(int *stack, int size);
int ft_sorted_percent_rev_desc(int *stack, int size);
int ft_sorted_percent_desc(int *stack, int size);


int	main(int argc, char **argv)
{
	struct int_arr	*stack_a;
	struct int_arr	*stack_b;

	//int i;
	//int total_size;



	stack_a = valid_input(argc, argv);
	if (!stack_a->array)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	stack_b = (struct int_arr *)malloc(sizeof(struct int_arr));
	if (!stack_b)
	{
		free(stack_a->array);
		free(stack_a);
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	stack_b->size = 0;
	stack_b->array = (int *)malloc(sizeof(int) * stack_a->size);
	if (!stack_b->array)
	{
		free(stack_a->array);
		free(stack_a);
		free(stack_b);
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	/*
	if (!ft_sorted(stack_a->array, stack_a->size))
	{
		total_size = stack_a->size;
		i = 0;
		while (i < 2 && total_size > 4)
		{
			push(stack_a, stack_b, "pb");
			i++;
		}
	}
	*/
	//i = 0;

	while (ft_sorted_percent(stack_a->array, stack_a->size) + ft_sorted_percent_rev(stack_a->array, stack_a->size) < 99)
	{
		//ft_putnbr_fd(ft_sorted_percent(stack_a->array, stack_a->size), 1);
		//ft_putendl_fd("%", 1);
		//ft_putnbr_fd(ft_sorted_percent_rev(stack_a->array, stack_a->size), 1);
		//ft_putendl_fd("% rev", 1);

		/*
		if (i++ > 20)
			break;
		//*/
		// 2. Sort stack_a and stack_b

		// 3. Merge stack_a and stack_b
		//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);

		if (check_swap(stack_a) && stack_a->size == 3)
			swap_head(stack_a->array, "sa");
		else if (check_swap(stack_a) && (check_swap_rev(stack_b) && stack_b->size > 1))
		{
			ss(stack_a->array, stack_b->array);
		}
		else if (check_swap_rev(stack_b))
			swap_head(stack_b->array, "sb");
		/*
		else if (check_for_rotate(stack_a) && (!check_for_rotate(stack_b) && stack_b->size > 1))
			rr(stack_a, stack_b);
		else if (check_reverse_rotate(stack_a) && (!check_reverse_rotate(stack_b) && stack_b->size > 1))
			rrr(stack_a, stack_b);
		*/


		/*
		else if (check_reverse_rotate(stack_a) && stack_a->size == 3)
			reverse_rotate(stack_a, "rra");
		else if (check_for_rotate(stack_a)	&& stack_a->size == 3)
			rotate(stack_a, "ra");
			*/
		else if (stack_a->array[0] == min_value(stack_a->array, stack_a->size))
		{
			push (stack_a, stack_b, "pb");
			while (!ft_sorted_desc(stack_b->array, stack_b->size))
			{
				if (stack_b->array[0] < stack_b->array[stack_b->size - 1])
				{
					rotate(stack_b, "rb");
				}
				swap_head(stack_b->array, "sb");
				if (ft_sorted_desc(stack_b->array, stack_b->size))
					break;
				//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
				rotate(stack_b, "rb");
				//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
			}
		}
		else
			if (min_value_index(stack_a->array, stack_a->size) < (stack_a->size - min_value_index(stack_a->array, stack_a->size)))
			{
				if (min_value_index(stack_b->array, stack_b->size) < (stack_b->size - min_value_index(stack_b->array, stack_b->size)))
				{
					rr(stack_a, stack_b);
					break;
				}
				else
				{
					rotate(stack_a, "ra");
				}
			}
			else
			{
				reverse_rotate(stack_a, "rra");
			}
		/*
		else
		{
			if (min_value_index(stack_a->array, stack_a->size) < stack_a->size / 2)
			{
				rotate(stack_a, "ra");
			}
			else
			{
				reverse_rotate(stack_a, "rra");
			}
		}
		*/
			/*
			if (stack_b->array[0] < stack_a->array[0] && stack_b->array[0] > stack_a->array[stack_a->size - 1] && stack_b->size > 0)
			{
				push (stack_b, stack_a, "pa");
			}
			rotate(stack_a, "ra end");
			*/



		/*

		else if (check_for_rotate(stack_a))
			rotate(stack_a, "ra");
		else if (check_for_rotate(stack_b) && stack_b->size > 1)
			rotate(stack_b, "rb");


		else if (check_reverse_rotate(stack_a))
			reverse_rotate(stack_a, "rra");
		else if (check_reverse_rotate(stack_b) && stack_b->size > 1)
			reverse_rotate(stack_b, "rrb");

		else if (stack_b->size && stack_b->array[0] < stack_a->array[0] && stack_b->array[0] < stack_a->array[stack_a->size - 1])
			push(stack_b, stack_a,"pa");

		else if (header_fits(stack_a) && !ft_sorted(stack_a->array, stack_a->size))
			push(stack_a, stack_b, "pb");

		else
			rotate(stack_a, "ra");

		//*/

		//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
		//ft_putnbr_fd(ft_sorted_percent(stack_a->array, stack_a->size), 1);
		//ft_putendl_fd("%", 1);
		//ft_putnbr_fd(ft_sorted_percent_rev(stack_a->array, stack_a->size), 1);
		//ft_putendl_fd("% rev", 1);
		//ft_putnbr_fd(ft_sorted_percent(stack_a->array, stack_a->size) + ft_sorted_percent_rev(stack_a->array, stack_a->size), 1);
		//ft_putendl_fd("% total", 1);
	}
	while (stack_b->size)
	{
		if (ft_sorted(stack_a->array, stack_a->size) && stack_b->array[0] < stack_a->array[0] && stack_b->array[0] < stack_a->array[stack_a->size - 1])
				{
					push (stack_b, stack_a, "pa");
				}
		else
		{
			if (stack_b->array[0] < stack_a->array[0] && stack_b->array[0] > stack_a->array[stack_a->size - 1])
			{
				push (stack_b, stack_a, "pa");
			}
			else if (stack_b->array[0] > max_value(stack_a->array, stack_a->size) && stack_a->array[0] == min_value(stack_a->array, stack_a->size))
			{
				push (stack_b, stack_a, "pa");
			}
			else if (stack_b->array[0] < min_value(stack_a->array, stack_a->size) && stack_a->array[0] == min_value(stack_a->array, stack_a->size))
			{
				push (stack_b, stack_a, "pa");
			}
			else
			{
				if (check_swap_rev(stack_b))
				{
					swap_head(stack_b->array, "sb");
				}
				else if (stack_b->array[0] < stack_a->array[0])
				{
					reverse_rotate(stack_a, "rra");
				}
				else
				{
					rotate(stack_a, "ra");
				}

			}
		}
		//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
	}
	//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
	//ft_putnbr_fd(i, 1);
	while (!ft_sorted(stack_a->array, stack_a->size))
	{
		if (min_value_index(stack_a->array, stack_a->size) < (stack_a->size - min_value_index(stack_a->array, stack_a->size)))
		{
			rotate(stack_a, "ra");
		}
		else
		{
			reverse_rotate(stack_a, "rra");
		}
		//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
	}

	/*/
	ft_putnbr_fd(ft_sorted_percent(stack_a->array, stack_a->size), 1);
	ft_putendl_fd("%", 1);
	ft_putnbr_fd(ft_sorted_percent(stack_b->array, stack_b->size), 1);
	ft_putendl_fd("%", 1);

	ft_putnbr_fd(ft_sorted_percent_rev(stack_a->array, stack_a->size), 1);
	ft_putendl_fd("% rev", 1);
	ft_putnbr_fd(ft_sorted_percent_rev(stack_b->array, stack_b->size), 1);
	ft_putendl_fd("% rev", 1);
	//*/
	//print_stacks(stack_a, stack_b, size_a, size_b);
		free(stack_a->array);
		free(stack_a);
		free(stack_b->array);
		free(stack_b);
}

void	print_stacks(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;

	i = 0;
	ft_putstr_fd("Stack A: ", 1);
	while (i < size_a)
	{
		ft_putnbr_fd(stack_a[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putendl_fd("", 1);
	i = 0;
	ft_putstr_fd("Stack B: ", 1);
	while (i < size_b)
	{
		ft_putnbr_fd(stack_b[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putendl_fd("", 1);
}

int header_fits(t_int_arr *stack)
{
	return ((stack->array[0] < stack->array[1]) && (stack->array[0] < stack->array[stack->size - 1]));
}

int ft_sorted_percent(int *stack, int size)
{
	int i;
	int sorted;
	int percent;

	i = 0;
	sorted = stack[0] > stack[size - 1];
	while (i < size - 1)
	{
		if (stack[i] < stack[i + 1])
			sorted++;
		else
			break;
		i++;
	}
	percent = (sorted * 100) / size;
	return (percent);
}

int ft_sorted_percent_rev(int *stack, int size)
{
	int i;
	int sorted;
	int percent;

	i = size - 1;
	sorted = (stack[0] > stack[size - 1]);
	while (i > 0)
	{
		if (stack[i - 1] < stack[i])
			sorted++;
		else
			break;
		i--;
	}
	percent = (sorted * 100) / size;
	return (percent);
}

int ft_sorted_percent_rev_desc(int *stack, int size)
{
	int i;
	int sorted;
	int percent;

	i = size - 1;
	sorted = 1;
	while (i > 0)
	{
		if (stack[i - 1] > stack[i])
			sorted++;
		else
			break;
		i--;
	}
	percent = (sorted * 100) / (size - 1);
	return (percent);
}

int ft_sorted_percent_desc(int *stack, int size)
{
	int i;
	int sorted;
	int percent;

	i = 0;
	sorted = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			sorted++;
		else
			break;
		i++;
	}
	percent = (sorted * 100) / size;
	return (percent);
}


int max_value(int *stack, int size)
{
	int i;
	int max;

	i = 1;
	max = stack[0];
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}

int min_value(int *stack, int size)
{
	int i;
	int min;

	i = 1;
	min = stack[0];
	while (i < size)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int min_value_index(int *stack, int size)
{
	int i;
	int min;
	int index;

	i = 1;
	min = stack[0];
	index = 0;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}
