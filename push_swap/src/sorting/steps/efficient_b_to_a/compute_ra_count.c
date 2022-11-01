/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ra_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:12:54 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 22:12:54 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	compute_ra_count(
		const t_ft_lvec *stack_a,
		size_t min_val_idx,
		long new_elem
		)
{
	size_t	i;
	size_t	next_i;

	i = min_val_idx;
	next_i = i + 1;
	if (i == stack_a->length - 1)
		next_i = 0;
	while (next_i != min_val_idx
		&& !(stack_a->data[i] < new_elem && new_elem < stack_a->data[next_i]))
	{
		if (next_i == stack_a->length - 1)
			next_i = 0;
		else
			next_i++;
		if (i == stack_a->length - 1)
			i = 0;
		else
			i++;
	}
	return (next_i);
}
