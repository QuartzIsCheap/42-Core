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

int	push_b_back_to_a(
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
