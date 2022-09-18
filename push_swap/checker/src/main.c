/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:34:10 by aronez            #+#    #+#             */
/*   Updated: 2022/09/18 12:34:10 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>

#include "instruction.h"
#include "stack.h"
#include "stack/creation.h"

int	handle_parsing_error(char *line, t_instruction *instructions)
{
	while (line != NULL)
	{
		free(line);
		line = ft_get_next_line(0);
	}
	free(instructions);
	return (-1);
}

int	try_parse_instructions(t_instruction **instructions)
{
	size_t	capacity;
	size_t	i;
	char	*line;

	capacity = 16 * sizeof(t_instruction);
	*instructions = malloc(capacity);
	i = 0;
	line = ft_get_next_line(0);
	while (line != NULL)
	{
		if (try_parse_instruction(line, *instructions + i) < 0)
			return (handle_parsing_error(line, *instructions));
		i++;
		if (i * sizeof(t_instruction) == capacity)
		{
			*instructions = ft_realloc(*instructions, capacity, capacity);
			if (*instructions == NULL)
				return (handle_parsing_error(line, *instructions));
			capacity *= 2;
		}
		free(line);
		line = ft_get_next_line(0);
	}
	(*instructions)[i] = NULL;
	return (0);
}

int	apply_instructions(t_stack *stack_a, t_instruction *instructions)
{
	t_stack	stack_b;
	size_t	i;

	if (try_create_empty_stack(stack_a->capacity, &stack_b) < 0)
		return (-1);
	i = 0;
	while (instructions[i] != NULL)
	{
		instructions[i](stack_a, &stack_b);
		i++;
	}
	free_stack(stack_b);
	return (0);
}

int	is_stack_full_and_sorted(t_stack stack)
{
	size_t	i;

	if (stack.length < stack.capacity)
		return (0);
	i = 0;
	while (i < stack.length - 1)
	{
		if (stack.data[i] > stack.data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	t_stack			stack_a;
	t_instruction	*instructions;

	if (try_parse_stack(argc, argv, &stack_a) < 0)
	{
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	if (try_parse_instructions(&instructions) < 0)
	{
		ft_putendl_fd("Error", 2);
		return (free_stack(stack_a), EXIT_FAILURE);
	}
	if (apply_instructions(&stack_a, instructions) < 0)
	{
		ft_putendl_fd("Error", 2);
		return (free_stack(stack_a), free(instructions), EXIT_FAILURE);
	}
	if (!is_stack_full_and_sorted(stack_a))
	{
		ft_putendl_fd("KO", 1);
		return (free_stack(stack_a), free(instructions), EXIT_FAILURE);
	}
	ft_putendl_fd("OK", 1);
	return (free_stack(stack_a), free(instructions), EXIT_SUCCESS);
}
