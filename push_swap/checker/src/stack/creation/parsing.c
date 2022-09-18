/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:34:10 by aronez            #+#    #+#             */
/*   Updated: 2022/09/18 12:34:10 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

#include "../../stack.h"

static int	checked_stack_capacity(int argc, size_t *length)
{
	if (argc == 1)
		return (-1);
	*length = (size_t)argc - 1;
	return (0);
}

static int	elem_already_present(const int *data, size_t elem_index)
{
	size_t	i;

	i = 0;
	while (i < elem_index)
	{
		if (data[i] == data[elem_index])
			return (1);
		i++;
	}
	return (0);
}

static int	try_parse_argv(size_t count, char *argv[], int *data)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (ft_s_atoi(argv[i + 1], data + i) < 0)
			return (-1);
		if (elem_already_present(data, i))
			return (-1);
		i++;
	}
	return (0);
}

int	try_parse_stack(int argc, char *argv[], t_stack *stack)
{
	if (checked_stack_capacity(argc, &stack->capacity) < 0)
		return (-1);
	stack->length = stack->capacity;
	stack->data = malloc(sizeof(int) * stack->capacity);
	if (stack->data == NULL)
		return (-1);
	if (try_parse_argv(stack->length, argv, stack->data) < 0)
		return (free(stack->data), -1);
	return (0);
}
