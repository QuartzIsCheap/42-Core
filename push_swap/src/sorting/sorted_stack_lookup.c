/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack_lookup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:12:24 by aronez            #+#    #+#             */
/*   Updated: 2022/10/28 15:12:24 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	index_of_min_a_value(const t_ft_lvec *stack_a)
{
	size_t	idx;

	if (stack_a->data[0] <= stack_a->data[stack_a->length - 1])
		return (0);
	idx = 1;
	while (stack_a->data[idx - 1] < stack_a->data[idx])
		idx++;
	return (idx);
}

size_t	index_of_min_b_value(const t_ft_lvec *stack_b)
{
	size_t	idx;

	if (stack_b->data[0] >= stack_b->data[stack_b->length - 1])
		return (stack_b->length - 1);
	idx = 0;
	while (stack_b->data[idx] > stack_b->data[idx + 1])
		idx++;
	return (idx);
}

size_t	index_of_max_a_value(const t_ft_lvec *stack_a)
{
	size_t	idx;

	if (stack_a->data[0] <= stack_a->data[stack_a->length - 1])
		return (stack_a->length - 1);
	idx = 0;
	while (stack_a->data[idx] < stack_a->data[idx + 1])
		idx++;
	return (idx);
}
