# include "push_swap.h"




void rotate(int *stack, int size, char *str)
{
	int i = 0;
	int tmp;
	tmp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
	if (*str)
		ft_putendl_fd(str, 1);
}

void rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate(stack_a, size_a, "");
	rotate(stack_b, size_b, "");
	ft_putendl_fd("rr", 1);
}

int check_for_ra(int *stack, int size)
{
	return (stack[0] > stack[size - 1]);
}

int check_for_rb(int *stack, int size)
{
	return (stack[0] < stack[size - 1]);
}


void reverse_rotate(int *stack, int size, char *str)
{
	int i = size - 1;
	int tmp;
	tmp = stack[size - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
	if (*str)
		ft_putendl_fd(str, 1);
}

void rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate(stack_a, size_a, "");
	rotate(stack_b, size_b, "");
	ft_putendl_fd("rrr", 1);
}

int check_for_rra(int *stack, int size)
{
	return (stack[size - 1] < stack[size - 2]);
}

int check_for_rrb(int *stack, int size)
{
	return (stack[size - 1] > stack[size - 2]);
}
