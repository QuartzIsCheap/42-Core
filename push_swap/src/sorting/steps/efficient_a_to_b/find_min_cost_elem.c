/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_cost_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:16:29 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 16:16:29 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../efficient_a_to_b.h"
#include "../../sorted_stack_lookup.h"

static size_t	compute_push_cost(
		const t_ft_lvec *stack_a,
		const t_ft_lvec *stack_b,
		size_t min_val_b_idx,
		size_t idx
		)
{
	size_t	push_cost;
	size_t	rb_count;

	push_cost = ft_smin(idx, stack_a->length - idx);
	rb_count = compute_rb_count(stack_b, min_val_b_idx, stack_a->data[idx]);
	push_cost += ft_smin(rb_count, stack_b->length - rb_count);
	return (push_cost);
}

size_t	find_min_cost_elem(
		const t_ft_lvec *stack_a,
		const t_ft_lvec *stack_b,
		t_ft_svec *lis,
		size_t min_val_b_idx
		)
{
	size_t	min_cost;
	size_t	min_cost_elem_idx;
	size_t	i;

	min_cost_elem_idx = first_non_lis_elem_idx(stack_a->length, lis);
	min_cost = compute_push_cost(
			stack_a, stack_b, min_val_b_idx, min_cost_elem_idx
			);
	i = -1;
	while (++i < stack_a->length)
	{
		if (ft_svec_contains(lis, i))
			continue ;
		if (min_cost > compute_push_cost(stack_a, stack_b, min_val_b_idx, i))
		{
			min_cost = compute_push_cost(stack_a, stack_b, min_val_b_idx, i);
			min_cost_elem_idx = i;
		}
	}
	return (min_cost_elem_idx);
}
