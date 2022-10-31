/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_rb_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:19:58 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 16:19:58 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	compute_rb_count(
		const t_ft_lvec *stack_b,
		size_t min_val_idx,
		long new_elem
		)
{
	size_t	prev_i;
	size_t	i;

	i = min_val_idx;
	prev_i = i - 1;
	if (i == 0)
		prev_i = stack_b->length - 1;
	while (prev_i != min_val_idx
		&& !(stack_b->data[prev_i] > new_elem && new_elem > stack_b->data[i]))
	{
		if (prev_i == 0)
			prev_i = stack_b->length - 1;
		else
			prev_i--;
		if (i == 0)
			i = stack_b->length - 1;
		else
			i--;
	}
	return (i);
}
