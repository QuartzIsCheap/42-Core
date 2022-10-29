/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_indexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:13:54 by aronez            #+#    #+#             */
/*   Updated: 2022/10/26 15:13:54 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	init_svec_with_length(t_ft_svec *svec, size_t length)
{
	if (ft_svec_with_capacity(svec, length) < 0)
		return (-1);
	ft_memset(svec->data, 0, sizeof(size_t) * length);
	svec->length = length;
	return (0);
}

static size_t	next_prefix(
		const t_ft_lvec *vec,
		size_t idx,
		size_t end_idx,
		const t_ft_svec *min_val_indexes
)
{
	size_t	begin_idx;
	size_t	mid_idx;

	begin_idx = 1;
	while (begin_idx < end_idx)
	{
		mid_idx = begin_idx + (end_idx - begin_idx) / 2;
		if (vec->data[min_val_indexes->data[mid_idx]] > vec->data[idx])
			end_idx = mid_idx;
		else
			begin_idx = mid_idx + 1;
	}
	return (begin_idx);
}

static size_t	generate_predecessors(
		const t_ft_lvec *vec,
		t_ft_svec *predecessors,
		t_ft_svec *min_val_indexes
)
{
	size_t	max_length;
	size_t	new_length;
	size_t	i;

	max_length = 0;
	i = -1;
	while (++i < vec->length)
	{
		new_length = next_prefix(vec, i, max_length + 1, min_val_indexes);
		predecessors->data[i] = min_val_indexes->data[new_length - 1];
		min_val_indexes->data[new_length] = i;
		if (new_length > max_length)
			max_length = new_length;
	}
	return (max_length);
}

static void	reconstruct_lis(
		size_t length,
		const t_ft_svec *predecessors,
		const t_ft_svec *min_val_indexes,
		t_ft_svec *lis
)
{
	size_t	i;
	size_t	prev_idx;

	i = length + 1;
	prev_idx = min_val_indexes->data[length];
	while (--i > 0)
	{
		lis->data[i - 1] = prev_idx;
		prev_idx = predecessors->data[prev_idx];
	}
}

int	find_lis_indexes(const t_ft_lvec *vec, t_ft_svec *lis)
{
	t_ft_svec	predecessors;
	t_ft_svec	min_val_indexes;
	size_t		max_length;

	if (init_svec_with_length(&predecessors, vec->length) < 0)
		return (-1);
	if (init_svec_with_length(&min_val_indexes, vec->length + 1) < 0)
		return (ft_svec_free(&predecessors), -1);
	max_length = generate_predecessors(vec, &predecessors, &min_val_indexes);
	if (init_svec_with_length(lis, max_length) < 0)
		return (ft_svec_free(&predecessors), ft_svec_free(&predecessors), -1);
	reconstruct_lis(max_length, &predecessors, &min_val_indexes, lis);
	return (ft_svec_free(&predecessors), ft_svec_free(&min_val_indexes), 0);
}
