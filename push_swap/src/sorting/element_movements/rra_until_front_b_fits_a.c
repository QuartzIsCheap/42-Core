/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_until_front_b_fits_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:21:09 by aronez            #+#    #+#             */
/*   Updated: 2022/10/28 17:21:09 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../stack.h"

int	rra_until_front_b_fits_a(
		t_ft_lvec *stack_a,
		long stack_b_front,
		t_ft_lvec *instructions
		)
{
	int	first_rotation;

	first_rotation = 1;
	while (stack_a->data[stack_a->length - 1] > stack_b_front
		&& (stack_a->data[0] > stack_a->data[stack_a->length - 1]
			|| first_rotation))
	{
		stack_rra(stack_a, NULL);
		if (ft_lvec_push_back(instructions, StackRRA) < 0)
			return (-1);
		first_rotation = 0;
	}
	return (0);
}
