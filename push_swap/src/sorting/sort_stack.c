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
#include "sorted_stack_lookup.h"
#include "steps.h"

int	sort_stack(t_ft_lvec *stack_a, t_ft_svec *lis, t_ft_lvec *instructions)
{
	t_ft_lvec	stack_b;

	if (ft_lvec_with_capacity(&stack_b, stack_a->length) < 0)
		return (-1);
	if (push_non_lis_elems_to_b(stack_a, &stack_b, lis, instructions) < 0)
		return (ft_lvec_free(&stack_b), -1);
	if (push_b_back_to_a(stack_a, &stack_b, instructions) < 0)
		return (ft_lvec_free(&stack_b), -1);
	if (rotate_a_efficiently(
			stack_a, instructions, index_of_min_a_value(stack_a)
		) < 0)
		return (ft_lvec_free(&stack_b), -1);
	ft_lvec_free(&stack_b);
	return (0);
}
