/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:00:47 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/15 22:01:04 by dkolida          ###   ########.fr       */
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
int max_value_index(int *stack, int size);
int ft_sorted_percent_rev_desc(int *stack, int size);
int ft_sorted_percent_desc(int *stack, int size);
int nearest_smaller_value(int *stack, int size, int value);
int nearest_larger_value(int *stack, int size, int value);
int moves_required(int *stack, int size, int value); 


int	main(int argc, char **argv)
{
	struct int_arr	*stack_a;
	struct int_arr	*stack_b;

	int max_rb = 0;
	int max_rrb = 0;
	int i = 0;
	int min_step_index = 0;

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

	while (ft_sorted_percent(stack_a->array, stack_a->size) + ft_sorted_percent_rev(stack_a->array, stack_a->size) < 99)
	{
		if (check_swap(stack_a) && stack_a->size == 3)
			swap_head(stack_a->array, "sa");

		// push two first elements to stack_b this will work for 5 elements
		else if (stack_b->size == 0)
		{
			while (stack_b->size < 2)
			{
				push(stack_a, stack_b, "pb");
			}
		}
		else
		{
			if ()

			
			else if (stack_a->array[0] < max_value(stack_b->array, stack_b->size))
			{

				
				//ft_putnbr_fd(nearest_larger_value(stack_b->array, stack_b->size, stack_a->array[0]), 1);
				if (moves_required(stack_b->array, stack_b->size, stack_a->array[0]) > (moves_required(stack_b->array, stack_b->size, stack_a->array[1] + 1)))
				{
					if (nearest_larger_value(stack_b->array, stack_b->size, stack_a->array[1]) < (stack_b->size - nearest_larger_value(stack_b->array, stack_b->size, stack_a->array[1])))
						rr(stack_a, stack_b);
					else
						rotate(stack_a, "ra");
				}
				else
				{
					i = 0;
					while(nearest_larger_value(stack_b->array, stack_b->size, stack_a->array[0]) != 0)
					{
						if (nearest_larger_value(stack_b->array, stack_b->size, stack_a->array[0]) < (stack_b->size - nearest_larger_value(stack_b->array, stack_b->size, stack_a->array[0])))
						{
							rotate(stack_b, "rb");
							i++;
							if (i > max_rb)
								max_rb = i;
						}
						
						else
						{
							reverse_rotate(stack_b, "rrb");
							i++;
							if (i > max_rrb)
								max_rrb = i;
						}
					}
					push(stack_a, stack_b, "pb");
				}

				
			}
			else
			{
				while(stack_b->array[0] != min_value(stack_b->array, stack_b->size))
				{
					if (min_value_index(stack_b->array, stack_b->size) < (stack_b->size - min_value_index(stack_b->array, stack_b->size)))
					{
						rotate(stack_b, "rb");
						i++;
						if (i > max_rb)
							max_rb = i;
					}
					else
					{
						reverse_rotate(stack_b, "rrb");
						i++;
						if (i > max_rrb)
							max_rrb = i;
					}
				}
				push(stack_a, stack_b, "pb");
			}
		}
		if (ft_sorted_percent_desc(stack_b->array, stack_b->size) + ft_sorted_percent_rev_desc(stack_b->array, stack_b->size) < 99)
			{
				print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
				ft_putnbr_fd(ft_sorted_percent_desc(stack_b->array, stack_b->size), 1);
				ft_putendl_fd("%", 1);
				ft_putnbr_fd(ft_sorted_percent_rev_desc(stack_b->array, stack_b->size), 1);
				ft_putendl_fd("% rev", 1);
				ft_putendl_fd("Error", 2);
				exit(0);
			}

		//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);

	}

	while (stack_b->size)
	{
		//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);

			if (stack_b->array[0] < max_value(stack_a->array, stack_a->size))
			{
				while(nearest_larger_value(stack_a->array, stack_a->size, stack_b->array[0]) != 0)
				{
					if (nearest_larger_value(stack_a->array, stack_a->size, stack_b->array[0]) < (stack_a->size - nearest_larger_value(stack_a->array, stack_a->size, stack_b->array[0])))
						rotate(stack_a, "ra");
					else
						reverse_rotate(stack_a, "rra");
				}
				push(stack_b, stack_a, "pa");
			}
			else
			{
				while(stack_a->array[0] != min_value(stack_a->array, stack_a->size))
				{
					if (min_value_index(stack_a->array, stack_a->size) < (stack_a->size - min_value_index(stack_a->array, stack_a->size)))
						rotate(stack_a, "ra");
					else
						reverse_rotate(stack_a, "rra");
				}
				push(stack_b, stack_a, "pa");
			}
		//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
	}
	//print_stacks(stack_a->array, stack_b->array, stack_a->size, stack_b->size);
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
		free(stack_a->array);
		free(stack_a);
		free(stack_b->array);
		free(stack_b);
		ft_putnbr_fd(max_rb, 1);
		ft_putendl_fd(" max_rb", 1);
		ft_putnbr_fd(max_rrb, 1);
		ft_putendl_fd(" max_rrb", 1);
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

int ft_sorted_percent_desc(int *stack, int size)
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

int max_value_index(int *stack, int size)
{
	int i;
	int max;
	int index;

	i = 1;
	max = stack[0];
	index = 0;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int nearest_larger_value(int *stack, int size, int value)
{
	int index = -1;
	int i = 0;

	while (i < size)
	{	
		if ((stack[i] > value) )
			{
				if (stack[i] < stack[index] || index == -1)
					index = i;
			}
		i++;
	}
	return (index);
}

int nearest_smaller_value(int *stack, int size, int value)
{
	int index = -1;
	int i = 0;

	while (i < size)
	{	
		if ((stack[i] < value) )
			{
				if (stack[i] > stack[index] || index == -1)
					index = i;
			}
		i++;
	}
	return (index);
}

int moves_required(int *stack, int size, int value)
{
	int moves_up = nearest_larger_value(stack, size, value);
	int moves_down = size - nearest_larger_value(stack, size, value);
	if (nearest_larger_value(stack, size, value) < (size - nearest_larger_value(stack, size, value)))
		return (moves_up);
	else
		return (moves_down);
}

int optimal_value_for_push(t_int_arr *stack_a, t_int_arr *stack_b)
{
	int i = 0;
	int min_step_index = 0;
	
	while (i < stack_a->size)
	{
		if (moves_required(stack_b->array, stack_b->size, stack_a->array[min_step_index]) > (moves_required(stack_b->array, stack_b->size, stack_a->array[i] + i)))
		{
			min_step_index = i;
		}
		i++;
	}
	
	if (min_step_index < stack_a->size - min_step_index)
	{
		return (min_step_index);
	}
	else if (min_step_index > stack_a->size - min_step_index)
	{
		return (min_step_index - stack_a->size);
	}
	else
	{
		return (0);
	}
	
}
