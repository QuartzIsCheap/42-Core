/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_compressions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:54:51 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 15:54:51 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../../stack.h"

static void	overwrite_extra_ra(
		t_ft_lvec *sa_ra,
		size_t first_ra_idx,
		size_t ra_gained
		)
{
	long	*rra_cluster_next;
	long	*ra_cluster_next;
	size_t	beyond_ra_cluster_element_count;

	rra_cluster_next = sa_ra->data + (first_ra_idx + 1 - ra_gained);
	ra_cluster_next = sa_ra->data + (first_ra_idx + 1);
	beyond_ra_cluster_element_count = sa_ra->length - first_ra_idx - 1;
	ft_memmove(
		rra_cluster_next,
		ra_cluster_next,
		sizeof(long) * beyond_ra_cluster_element_count
		);
}

static void	replace_ra_with_rra(
		t_ft_lvec *sa_ra,
		size_t stack_len,
		size_t first_ra_idx,
		size_t ra_count
		)
{
	size_t	j;

	j = first_ra_idx + stack_len - 2 * ra_count;
	while (j < sa_ra->length && j >= first_ra_idx + 1 - ra_count)
	{
		sa_ra->data[j] = StackRRA;
		j--;
	}
}

static size_t	compress_ra_cluster(
		t_ft_lvec *sa_ra,
		size_t stack_len,
		size_t first_ra_idx
		)
{
	size_t	ra_count;
	size_t	ra_gained;

	ra_count = 0;
	while (first_ra_idx - ra_count < sa_ra->length
		&& sa_ra->data[first_ra_idx - ra_count] == StackRA)
		ra_count++;
	if (ra_count > stack_len - ra_count)
	{
		ra_gained = ra_count - (stack_len - ra_count);
		overwrite_extra_ra(sa_ra, first_ra_idx, ra_gained);
		replace_ra_with_rra(sa_ra, stack_len, first_ra_idx, ra_count);
		sa_ra->length -= ra_gained;
	}
	return (ra_count);
}

void	compress_rotates(t_ft_lvec *sa_ra, size_t stack_len)
{
	size_t	i;

	i = sa_ra->length - 1;
	while (i < sa_ra->length && sa_ra->data[i] != StackRA)
		i--;
	while (i < sa_ra->length)
	{
		i -= compress_ra_cluster(sa_ra, stack_len, i);
		while (i < sa_ra->length && sa_ra->data[i] != StackRA)
			i--;
	}
}
