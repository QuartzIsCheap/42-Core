/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_sorted_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:16:31 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 11:16:31 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../element_movements.h"
#include "../sorted_stack_lookup.h"
#include "efficient_b_to_a.h"

int	rotate_a_to_match_b(
		t_ft_lvec *stack_a,
		long stack_b_front,
		t_ft_lvec *instructions,
		t_ft_svec *lis
		)
{
	size_t	ra_count_to_fit_front_b;

	ra_count_to_fit_front_b = compute_ra_count(
			stack_a, index_of_min_a_value(stack_a), stack_b_front
			);
	if (rotate_a_efficiently(
			stack_a, instructions, lis, ra_count_to_fit_front_b
		) < 0)
		return (-1);
	return (0);
}

int	push_b_back_to_a(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
		)
{
	while (stack_b->length != 0)
	{
		if (rotate_a_to_match_b(
				stack_a, stack_b->data[0], instructions, lis
			) < 0)
			return (-1);
		while (stack_b->length != 0
			&& ((stack_a->data[stack_a->length - 1] < stack_b->data[0]
					&& stack_b->data[0] < stack_a->data[0])
				|| (index_of_max_a_value(stack_a) == stack_a->length - 1
					&& (stack_b->data[0] > stack_a->data[stack_a->length - 1]
						|| stack_b->data[0] < stack_a->data[0]))))
		{
			if (push_to_a(stack_a, stack_b, instructions) < 0)
				return (-1);
		}
	}
	return (0);
}
