/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../stack.h"

static void	stack_reverse_rotate(t_ft_lvec *stack)
{
	long	bot_elem;
	size_t	i;

	if (stack->length > 1)
	{
		bot_elem = stack->data[stack->length - 1];
		i = 1;
		while (i < stack->length)
		{
			stack->data[stack->length - i] = stack->data[stack->length - 1 - i];
			i++;
		}
		stack->data[0] = bot_elem;
	}
}

void	stack_rra(t_ft_lvec *stack_a, t_ft_lvec *stack_b)
{
	(void)stack_b;
	stack_reverse_rotate(stack_a);
}

void	stack_rrb(t_ft_lvec *stack_a, t_ft_lvec *stack_b)
{
	(void)stack_a;
	stack_reverse_rotate(stack_b);
}

void	stack_rrr(t_ft_lvec *stack_a, t_ft_lvec *stack_b)
{
	stack_reverse_rotate(stack_a);
	stack_reverse_rotate(stack_b);
}
