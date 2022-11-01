/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:24:26 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 10:24:26 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../stack.h"
#include "../../lis.h"

int	rotate_b_efficiently(
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions,
		size_t rb_count
)
{
	size_t	i;

	i = 0;
	if (rb_count < stack_b->length / 2)
	{
		while (i < rb_count)
		{
			stack_rb(NULL, stack_b);
			if (ft_lvec_push_back(instructions, StackRB) < 0)
				return (-1);
			i++;
		}
	}
	else
	{
		while (i < stack_b->length - rb_count)
		{
			stack_rrb(NULL, stack_b);
			if (ft_lvec_push_back(instructions, StackRRB) < 0)
				return (-1);
			i++;
		}
	}
	return (0);
}

int	rotate_a_efficiently(
		t_ft_lvec *stack_a,
		t_ft_lvec *instructions,
		size_t ra_count
)
{
	size_t	i;

	i = 0;
	if (ra_count < stack_a->length / 2)
	{
		while (i < ra_count)
		{
			stack_ra(stack_a, NULL);
			if (ft_lvec_push_back(instructions, StackRA) < 0)
				return (-1);
			i++;
		}
	}
	else
	{
		while (i < stack_a->length - ra_count)
		{
			stack_rra(stack_a, NULL);
			if (ft_lvec_push_back(instructions, StackRRA) < 0)
				return (-1);
			i++;
		}
	}
	return (0);
}
