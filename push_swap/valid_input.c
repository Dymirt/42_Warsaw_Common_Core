/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:52:18 by dkolida           #+#    #+#             */
/*   Updated: 2024/06/17 22:26:15 by dmytrokolid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_digit_array(char **array, int len);
int		itoa_check(int *stack, char **array, int len);
int		is_valid_array(t_int_arr *array, char **input_data);
char	**clean_data(int argc, char **argv, t_int_arr *array);

t_int_arr	*valid_input(int argc, char **argv)
{
	struct int_arr	*s;
	char			**data;

	s = (struct int_arr *)malloc(sizeof(struct int_arr));
	if (!s)
		return (s);
	s->size = 0;
	s->array = NULL;
	data = clean_data(argc, argv, s);
	if (!data)
		return (s);
	s->array = (int *)malloc(sizeof(int) * s->size);
	if (!s->array || !is_digit_array(data, s->size) || !is_valid_array(s, data))
	{
		free(s->array);
		s->array = NULL;
	}
	ft_free_2d(data, s->size);
	return (s);
}

char	**clean_data(int argc, char **argv, t_int_arr *array)
{
	char	**input_data;

	input_data = NULL;
	if (argc == 2)
	{
		input_data = ft_split(argv[1], ' ');
		if (input_data)
		{
			while (input_data[array->size] != NULL)
				array->size++;
		}
	}
	else if (argc > 2)
	{
		input_data = malloc(sizeof(char *) * (argc - 1));
		if (input_data)
		{
			while (argc-- - 1)
			{
				input_data[array->size] = ft_strdup(argv[array->size + 1]);
				array->size++;
			}
		}
	}
	return (input_data);
}

int	is_valid_array(t_int_arr *s, char **data)
{
	ft_arr_atoi(data, s->array, s->size);
	if (itoa_check(s->array, data, s->size) && is_arr_uniq(s->array, s->size))
		return (1);
	return (0);
}

int	is_digit_array(char **array, int len)
{
	while (len)
	{
		if (!is_int_str(array[len - 1]))
			return (0);
		len--;
	}
	return (1);
}

int	itoa_check(int *stack, char **array, int len)
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
