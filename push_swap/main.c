# include "push_swap.h"

int check_sort(int *stack_a, int size);
long long sum(int *stack, int size);
int average(int *stack_a, int *stack_b, int size_a, int size_b);

int check_sort_rev(int *stack_b);
void print_stacks(int *stack_a, int *stack_b, int size_a, int size_b);

int	main(int argc, char **argv)
{
	int size_a;
	int size_b = 0;
	int *stack_a;
	int *stack_b;
	int average;
	struct array *array;

	array = valid_input(argc, argv);

	if (!array->array)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	size_a = array->size;
	stack_a = array->array;


	stack_b = ft_calloc(size_a, sizeof(int));

	average = sum(stack_a, size_a) / size_a;

	while (!check_sort(stack_a, size_a) || size_b)
	{
		//print_stacks(stack_a, stack_b, size_a, size_b);
		if (check_for_ra(stack_a, size_a, average) && check_for_rb(stack_b, size_b, average))
			rr(stack_a, stack_b, size_a, size_b);
		else if (check_for_ra(stack_a, size_a, average))
			rotate(stack_a, size_a, "ra");
		else if (check_for_rra(stack_a, size_a, average))
			reverse_rotate(stack_a, size_a, "rra");
		else if (stack_a[0] > stack_a[1] && stack_b[0] < stack_b[1])
			ss(stack_a, stack_b);
		else if (stack_a[0] > stack_a[1])
			swap_head(stack_a, "sa");
		else if (stack_a[0] < stack_a[1] && !check_sort(stack_a, size_a))
			pb(stack_a, stack_b, &size_a, &size_b);
		else if (size_b)
			pa(stack_a, stack_b, &size_a, &size_b);
	}
	//print_stacks(stack_a, stack_b, size_a, size_b);
}

int check_sort(int *stack_a, int size)
{
	int i = 0;
	while (i < size - 1)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void print_stacks(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int i = 0;
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

long long sum(int *stack, int size)
{
	long long sum = 0;
	int i = 0;
	while (i < size)
	{
		sum += stack[i];
		i++;
	}
	return (sum);
}
