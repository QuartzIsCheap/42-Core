/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:56:00 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 14:56:00 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../lis.h"
#include "../../stack.h"

int	push_to_a(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
)
{
	stack_pa(stack_a, stack_b);
	if (ft_lvec_push_back(instructions, StackPA) < 0)
		return (-1);
	return (0);
}

int	push_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions,
		t_ft_svec *lis
		)
{
	stack_pb(stack_a, stack_b);
	if (ft_lvec_push_back(instructions, StackPB) < 0)
		return (-1);
	offset_lis(lis, -1, stack_a->length);
	return (0);
}
