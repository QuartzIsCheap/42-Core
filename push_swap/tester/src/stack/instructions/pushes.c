/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	stack_push(t_ft_lvec *stack_from, t_ft_lvec *stack_to)
{
	size_t	i;

	if (stack_from->length != 0)
	{
		i = stack_to->length;
		while (i > 0)
		{
			stack_to->data[i] = stack_to->data[i - 1];
			i--;
		}
		stack_to->length++;
		stack_to->data[0] = stack_from->data[0];
		stack_from->length--;
		i = 1;
		while (i < stack_from->length + 1)
		{
			stack_from->data[i - 1] = stack_from->data[i];
			i++;
		}
	}
}

void	stack_pa(t_ft_lvec *stack_a, t_ft_lvec *stack_b)
{
	stack_push(stack_b, stack_a);
}

void	stack_pb(t_ft_lvec *stack_a, t_ft_lvec *stack_b)
{
	stack_push(stack_a, stack_b);
}
