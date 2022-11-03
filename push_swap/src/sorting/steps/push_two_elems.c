/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_two_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:40:45 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 16:40:45 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "efficient_a_to_b.h"
#include "../element_movements.h"
#include "../../lis.h"
#include "../../stack.h"

static size_t	count_elems_to_push(size_t stack_a_len, size_t lis_len)
{
	if (stack_a_len <= 5)
		return (0);
	return (ft_smin(stack_a_len - 5, stack_a_len - lis_len));
}

static int	push_elem_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions,
		t_ft_svec *lis
		)
{
	size_t	non_lis_elem_idx;

	non_lis_elem_idx = first_non_lis_elem_idx(stack_a->length, lis);
	if (rotate_a_efficiently(stack_a, instructions, non_lis_elem_idx) < 0)
		return (ft_lvec_free(stack_a), ft_lvec_free(stack_b), -1);
	offset_lis(lis, -1 * (long)non_lis_elem_idx, stack_a->length);
	if (push_to_b(stack_a, stack_b, instructions) < 0)
		return (ft_lvec_free(stack_a), ft_lvec_free(stack_b), -1);
	offset_lis(lis, -1, stack_a->length);
	return (0);
}

int	push_two_elems_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
		)
{
	size_t	elems_to_push_count;
	size_t	i;

	elems_to_push_count = count_elems_to_push(stack_a->length, lis->length);
	i = -1;
	while (++i < elems_to_push_count)
	{
		if (push_elem_to_b(stack_a, stack_b, instructions, lis) < 0)
			return (-1);
	}
	if (elems_to_push_count == 2 && stack_b->data[0] < stack_b->data[1])
	{
		stack_sb(NULL, stack_b);
		if (ft_lvec_push_back(instructions, StackSB) < 0)
			return (ft_lvec_free(stack_a), ft_lvec_free(stack_b), -1);
	}
	return (0);
}
