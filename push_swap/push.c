#include "push_swap.h"


void pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int i = *size_b;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	(*size_b) ++;
	i = 0;
	(*size_a) --;
	while (i < *size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}

	write(1, "pb\n", 3);
}

void pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int i = *size_a;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	(*size_a) ++;
	(*size_b) --;
	i = 0;
	while (i < *size_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
}


