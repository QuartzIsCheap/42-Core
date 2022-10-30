/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:49:48 by aronez            #+#    #+#             */
/*   Updated: 2022/10/30 17:49:48 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../stack.h"

void	compress_instructions_pair(
		t_ft_lvec *instructions,
		t_stack_instruction other_instruction,
		t_stack_instruction combination_instruction,
		size_t instruction_index
)
{
	size_t	i;

	i = instruction_index - 1;
	while (
		i < instructions->length
		&& (instructions->data[i] == instructions->data[instruction_index]
			|| instructions->data[i] == combination_instruction)
	)
		i--;
	if (i < instructions->length && instructions->data[i] == other_instruction)
	{
		instructions->data[i] = combination_instruction;
		ft_memmove(
			instructions->data + (instruction_index + 0),
			instructions->data + (instruction_index + 1),
			sizeof(long) * (instructions->length - instruction_index - 1)
			);
		instructions->length--;
	}
}

void	compress_instructions(t_ft_lvec *instructions)
{
	size_t	i;

	i = instructions->length - 1;
	while (i < instructions->length)
	{
		if (instructions->data[i] == StackRA)
			compress_instructions_pair(instructions, StackRB, StackRR, i);
		else if (instructions->data[i] == StackRB)
			compress_instructions_pair(instructions, StackRA, StackRR, i);
		else if (instructions->data[i] == StackRRA)
			compress_instructions_pair(instructions, StackRRB, StackRRR, i);
		else if (instructions->data[i] == StackRRB)
			compress_instructions_pair(instructions, StackRRA, StackRRR, i);
		i--;
	}
}
