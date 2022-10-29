/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_sorted_a_until_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:46:29 by aronez            #+#    #+#             */
/*   Updated: 2022/10/28 17:46:29 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../stack.h"

int	rra_sorted_a_until_main(t_ft_lvec *stack_a, t_ft_lvec *instructions)
{
	while (stack_a->data[0] > stack_a->data[stack_a->length - 1])
	{
		stack_rra(stack_a, NULL);
		if (ft_lvec_push_back(instructions, StackRRA) < 0)
			return (-1);
	}
	return (0);
}

int	rra_sorted_b_until_main(t_ft_lvec *stack_b, t_ft_lvec *instructions)
{
	while (stack_b->data[0] < stack_b->data[stack_b->length - 1])
	{
		stack_rrb(NULL, stack_b);
		if (ft_lvec_push_back(instructions, StackRRB) < 0)
			return (-1);
	}
	return (0);
}
