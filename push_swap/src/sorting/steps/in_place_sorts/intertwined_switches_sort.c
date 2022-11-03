/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intertwined_switches_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:27:04 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:27:04 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "switches_interleaving.h"
#include "../in_place_sorts.h"
#include "../../../stack.h"

static int	is_last_config(const t_ft_lvec *sa_ra, size_t sa_count)
{
	size_t	i;

	i = -1;
	while (++i < sa_count)
	{
		if (sa_ra->data[sa_ra->length - 1 - 2 * i] != StackSA)
			return (0);
	}
	return (1);
}

int	try_sort_with_switches(
		const t_ft_lvec *stack_a,
		t_ft_lvec *wrk_a,
		t_ft_lvec *sa_ra,
		size_t ra_count
)
{
	size_t	sa_count;

	sa_count = 0;
	while (!is_vec_sorted(wrk_a) && ++sa_count <= ra_count + 1)
	{
		if (reset_work_arrays(stack_a, wrk_a, sa_ra) < 0)
			return (-1);
		if (try_sort_with_begin_switches(wrk_a, sa_ra, ra_count, sa_count) < 0)
			return (-1);
		while (!is_vec_sorted(wrk_a) && !is_last_config(sa_ra, sa_count))
		{
			if (ft_lvec_assign(stack_a, wrk_a) < 0)
				return (-1);
			if (try_sort_with_next_switches(wrk_a, sa_ra) < 0)
				return (-1);
		}
	}
	return (0);
}
