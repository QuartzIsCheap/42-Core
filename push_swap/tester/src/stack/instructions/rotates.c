/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	stack_rotate(t_ft_lvec *stack)
{
	long	top_elem;
	size_t	i;

	if (stack->length > 1)
	{
		top_elem = stack->data[0];
		i = 0;
		while (i < stack->length - 1)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->length - 1] = top_elem;
	}
}

void	stack_ra(t_ft_lvec *stack_a, t_ft_lvec *stack_b)
{
	(void)stack_b;
	stack_rotate(stack_a);
}

void	stack_rb(t_ft_lvec *stack_a, t_ft_lvec *stack_b)
{
	(void)stack_a;
	stack_rotate(stack_b);
}

void	stack_rr(t_ft_lvec *stack_a, t_ft_lvec *stack_b)
{
	stack_rotate(stack_a);
	stack_rotate(stack_b);
}
