# include "push_swap.h"

void	swap_head(int *stack, char *str)
{
	int tmp;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	if (*str)
		ft_putendl_fd(str, 1);

}

void ss(int *stack_a, int *stack_b)
{
	swap_head(stack_a, "");
	swap_head(stack_b, "");
	ft_putendl_fd("ss", 1);
}
