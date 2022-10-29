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

#include "libft.h"

size_t	index_of_min_b_value(const t_ft_lvec *stack_b)
{
	size_t	idx;

	if (stack_b->data[0] > stack_b->data[stack_b->length - 1])
		return (stack_b->length - 1);
	idx = 0;
	while (stack_b->data[idx] > stack_b->data[idx + 1])
		idx++;
	return (idx);
}
