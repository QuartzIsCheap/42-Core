/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../stack.h"

static void	stack_swap(t_stack *stack)
{
	int	temp;

	if (stack->length > 1)
	{
		temp = stack->data[0];
		stack->data[0] = stack->data[1];
		stack->data[1] = temp;
	}
}

void	stack_sa(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	stack_swap(stack_a);
}

void	stack_sb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	stack_swap(stack_b);
}

void	stack_ss(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
}
