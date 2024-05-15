# include "push_swap.h"

int check_sort(int *stack_a, int size);
void pb(int *stack_a, int *stack_b, int *size_a, int *size_b);
void pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
int check_sort_rev(int *stack_b);
void print_stacks(int *stack_a, int *stack_b, int size_a, int size_b);

int	main(int argc, char **argv)
{
	int i = 0;
	int size_a = argc - 1;
	int size_b = 0;
	int stack_a[size_a];
	int stack_b[size_a];
	char **split;

	int a;

	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	}

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i])
		{
			stack_a[i] = ft_atoi(split[i]);
			i++;
			size_a = i;
		}
	}

	else
	{
		while (i < argc - 1)
		{
			a = ft_atoi(argv[i + 1]);
			if (!a)
			{
				printf("%dError\n", a);
				return (0);
			}
			stack_a[i] = a;
			i++;
		}
	}

	while (!check_sort(stack_a, size_a) || size_b)
	{

		//print_stacks(stack_a, stack_b, size_a, size_b);

		if (check_for_ra(stack_a, size_a) && check_for_rb(stack_b, size_b))
		{
			rr(stack_a, stack_b, size_a, size_b);
			continue;
		}

		if (check_for_ra(stack_a, size_a))
		{
			rotate(stack_a, size_a, "ra");
			continue;
		}

		if (stack_a[0] > stack_a[1] && check_sort_rev(stack_b))
		{
			ss(stack_a, stack_b);
			continue;
		}

		if (stack_a[0] > stack_a[1])
		{
			swap_head(stack_a, "sa");
			continue;
		}

		if (stack_a[0] < stack_a[1] && !check_sort(stack_a, size_a))
		{
			pb(stack_a, stack_b, &size_a, &size_b);
			continue;
		}

		if (size_b)
		{
			pa(stack_a, stack_b, &size_a, &size_b);
			continue;
		}
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

int check_sort_rev(int *stack_b)
{
	return (stack_b[0] < stack_b[1]);
}

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
