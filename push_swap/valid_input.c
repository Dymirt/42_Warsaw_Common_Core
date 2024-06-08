/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolida <dkolida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:52:18 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/08 17:23:44 by dkolida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isdigit_str(char *str);
void	free_split(char **split, int len);
int		is_digit_array(char **array, int len);
void	array_to_int(char **array, int *stack, int len);
int		is_unique_int_array(int *array, int len);
int		integrity_check(int *stack, char **array, int len);

t_int_arr	*valid_input(int argc, char **argv)
{
	char			**split;
	int				*stack;
	struct int_arr	*array;

	array = (struct int_arr *)malloc(sizeof(struct int_arr));
	array->size = 0;
	array->array = NULL;
	split = NULL;
	stack = NULL;
	if (argc < 2)
		return (array);
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (array);
		while (split[array->size] != NULL)
			array->size++;
		if (!is_digit_array(split, array->size))
		{
			free_split(split, array->size);
			return (array);
		}
	}
	else
	{
		array->size = argc - 1;
		if (!is_digit_array(argv + 1, array->size))
			return (array);
	}
	stack = (int *)malloc(sizeof(int) * array->size);
	if (!stack)
	{
		free_split(split, array->size);
		return (array);
	}
	if (argc == 2)
	{
		array_to_int(split, stack, array->size);
		if (!integrity_check(stack, split, array->size))
		{
			free(stack);
			stack = NULL;
		}
		free_split(split, array->size);
	}
	else
	{
		array_to_int(argv + 1, stack, array->size);
		if (!integrity_check(stack, argv + 1, array->size))
		{
			free(stack);
			stack = NULL;
		}
	}
	if (!is_unique_int_array(stack, array->size))
	{
		free(stack);
		stack = NULL;
	}
	array->array = stack;
	return (array);
}

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 11)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' && i == 0 && ft_isdigit(str[i + 1]))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split, int len)
{
	while (len--)
		free(split[len]);
	free(split);
}

int	is_digit_array(char **array, int len)
{
	while (len)
	{
		if (!ft_isdigit_str(array[len - 1]))
			return (0);
		len--;
	}
	return (1);
}

void	array_to_int(char **array, int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[i] = ft_atoi(array[i]);
		i++;
	}
}

int	is_unique_int_array(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < i)
		{
			if (array[j] == array[i])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	integrity_check(int *stack, char **array, int len)
{
	int		i;
	char	*str;

	i = 0;
	while (i < len)
	{
		str = ft_itoa(stack[i]);
		if (ft_strncmp(str, array[i], ft_strlen(str)))
		{
			free(str);
			str = NULL;
			return (0);
		}
		free(str);
		str = NULL;
		i++;
	}
	return (1);
}
