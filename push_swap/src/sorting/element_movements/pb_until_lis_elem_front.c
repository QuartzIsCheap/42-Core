/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_with_sorting_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:22:17 by aronez            #+#    #+#             */
/*   Updated: 2022/10/28 10:22:17 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../stack.h"
#include "../../lis.h"
#include "../sorted_stack_lookup.h"

static size_t	compute_rb_count(
		const t_ft_lvec *stack_b,
		size_t min_val_idx,
		long new_elem
		)
{
	size_t	prev_i;
	size_t	i;

	i = min_val_idx;
	prev_i = i - 1;
	if (i == 0)
		prev_i = stack_b->length - 1;
	while (prev_i != min_val_idx
		&& !(stack_b->data[prev_i] > new_elem && new_elem > stack_b->data[i]))
	{
		if (prev_i == 0)
			prev_i = stack_b->length - 1;
		else
			prev_i--;
		if (i == 0)
			i = stack_b->length - 1;
		else
			i--;
	}
	return (i);
}

static int	rotate_b_efficiently(
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions,
		size_t rb_count
		)
{
	size_t	i;

	i = 0;
	if (rb_count < stack_b->length / 2)
	{
		while (i < rb_count)
		{
			stack_rb(NULL, stack_b);
			if (ft_lvec_push_back(instructions, StackRB) < 0)
				return (-1);
			i++;
		}
	}
	else
	{
		while (i < stack_b->length - rb_count)
		{
			stack_rrb(NULL, stack_b);
			if (ft_lvec_push_back(instructions, StackRRB) < 0)
				return (-1);
			i++;
		}
	}
	return (0);
}

static int	rotate_b_to_insert(
		t_ft_lvec *stack_b,
		long new_elem,
		t_ft_lvec *instructions
		)
{
	size_t	min_val_idx;
	size_t	rb_count;

	rb_count = 0;
	if (stack_b->length > 1)
	{
		min_val_idx = index_of_min_b_value(stack_b);
		rb_count = compute_rb_count(stack_b, min_val_idx, new_elem);
	}
	rotate_b_efficiently(stack_b, instructions, rb_count);
	return (0);
}

int	pb_with_sorting_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
	)
{
	rotate_b_to_insert(stack_b, stack_a->data[0], instructions);
	stack_pb(stack_a, stack_b);
	if (ft_lvec_push_back(instructions, StackPB) < 0)
		return (-1);
	offset_lis(lis, -1, stack_a->length);
	return (0);
}
