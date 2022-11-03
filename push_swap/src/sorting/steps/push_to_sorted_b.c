/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_sorted_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:10:31 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 11:10:31 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../element_movements.h"
#include "../sorted_stack_lookup.h"
#include "efficient_a_to_b.h"
#include "../../lis.h"

static int	first_push_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
		)
{
	size_t	first_elem_idx;

	first_elem_idx = first_non_lis_elem_idx(stack_a->length, lis);
	if (rotate_a_efficiently(stack_a, instructions, first_elem_idx) < 0)
		return (-1);
	offset_lis(lis, -1 * (long)first_elem_idx, stack_a->length);
	if (push_to_b(stack_a, stack_b, instructions) < 0)
		return (-1);
	offset_lis(lis, -1, stack_a->length);
	return (0);
}

static int	push_next_elem_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
		)
{
	size_t	next_elem_idx;
	size_t	min_val_b_idx;

	min_val_b_idx = index_of_min_b_value(stack_b);
	next_elem_idx = find_min_cost_elem(stack_a, stack_b, lis, min_val_b_idx);
	if (rotate_b_efficiently(
			stack_b,
			instructions,
			compute_rb_count(
				stack_b, min_val_b_idx, stack_a->data[next_elem_idx]
			)
		) < 0)
		return (-1);
	if (rotate_a_efficiently(
			stack_a, instructions, next_elem_idx
		) < 0)
		return (-1);
	offset_lis(lis, -1 * (long)next_elem_idx, stack_a->length);
	if (push_to_b(stack_a, stack_b, instructions) < 0)
		return (-1);
	offset_lis(lis, -1, stack_a->length);
	return (0);
}

int	push_non_lis_elems_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
		)
{
	if (stack_a->length <= 5 + 2 || stack_a->length - lis->length < 3)
		return (0);
	if (first_push_to_b(stack_a, stack_b, lis, instructions) < 0)
		return (-1);
	while (stack_a->length > 5 + 2 && stack_a->length - lis->length >= 3)
	{
		if (push_next_elem_to_b(stack_a, stack_b, lis, instructions) < 0)
			return (-1);
	}
	return (0);
}
