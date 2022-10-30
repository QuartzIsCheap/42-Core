/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:54:22 by aronez            #+#    #+#             */
/*   Updated: 2022/10/27 18:54:22 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "element_movements.h"

static size_t	index_of_min_lis_value(const t_ft_svec *lis)
{
	size_t	i;

	i = lis->length - 1;
	while (lis->data[i - 1] <= lis->data[i])
		i--;
	return (i);
}

static int	push_non_lis_elems_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
		)
{
	size_t	min_i;
	size_t	i;

	min_i = index_of_min_lis_value(lis);
	i = -1;
	while (++i < lis->length)
	{
		while (lis->data[min_i] != 0)
		{
			if (pb_with_sorting_b(stack_a, stack_b, lis, instructions) < 0)
				return (-1);
		}
		if (ra_once(stack_a, lis, instructions) < 0)
			return (-1);
		min_i = (min_i + 1) % lis->length;
	}
	while (lis->data[min_i] != 0)
	{
		if (pb_with_sorting_b(stack_a, stack_b, lis, instructions) < 0)
			return (-1);
	}
	return (0);
}

static int	push_b_back_to_a(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
		)
{
	if (rra_sorted_a_until_main(stack_a, instructions) < 0)
		return (-1);
	if (rrb_sorted_b_until_main(stack_b, instructions) < 0)
		return (-1);
	while (stack_b->length != 0)
	{
		if (rra_until_front_b_fits_a(
				stack_a,
				stack_b->data[0],
				instructions
			) < 0)
			return (-1);
		if (pa_until_next_lis_elem(stack_a, stack_b, instructions) < 0)
			return (-1);
	}
	return (0);
}

int	sort_stack(t_ft_lvec *stack_a, t_ft_svec *lis, t_ft_lvec *instructions)
{
	t_ft_lvec	stack_b;

	if (ft_lvec_with_capacity(&stack_b, stack_a->length) < 0)
		return (-1);
	if (push_non_lis_elems_to_b(stack_a, &stack_b, lis, instructions) < 0)
		return (ft_lvec_free(&stack_b), -1);
	if (push_b_back_to_a(stack_a, &stack_b, instructions) < 0)
		return (ft_lvec_free(&stack_b), -1);
	if (rra_sorted_a_until_main(stack_a, instructions) < 0)
		return (ft_lvec_free(&stack_b), -1);
	ft_lvec_free(&stack_b);
	return (0);
}
