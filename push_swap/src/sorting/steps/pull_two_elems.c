/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_two_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:18:34 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 17:18:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "efficient_b_to_a.h"
#include "../element_movements.h"

int	pull_two_elems_from_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
		)
{
	size_t	elems_to_pull_count;
	size_t	i;

	elems_to_pull_count = ft_smin(2, stack_b->length);
	i = -1;
	while (++i < elems_to_pull_count)
	{
		if (rotate_a_to_match_b(stack_a, stack_b->data[0], instructions) < 0)
			return (ft_lvec_free(stack_a), ft_lvec_free(stack_b), -1);
		if (push_to_a(stack_a, stack_b, instructions) < 0)
			return (ft_lvec_free(stack_a), ft_lvec_free(stack_b), -1);
	}
	return (0);
}
