/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_until_next_lis_elem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:05:43 by aronez            #+#    #+#             */
/*   Updated: 2022/10/28 17:05:43 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../../stack.h"

int	pa_until_next_lis_elem(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
		)
{
	while (stack_b->length != 0
		&& (stack_a->data[stack_a->length - 1] < stack_b->data[0]
			|| stack_a->data[0] < stack_a->data[stack_a->length - 1]))
	{
		stack_pa(stack_a, stack_b);
		if (ft_lvec_push_back(instructions, StackPA) < 0)
			return (-1);
	}
	return (0);
}
