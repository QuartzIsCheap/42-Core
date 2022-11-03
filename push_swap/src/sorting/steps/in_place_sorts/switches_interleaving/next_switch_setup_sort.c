/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_switch_setup_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:46:25 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:46:25 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../../../stack.h"

static void	swap_switch_rotate(t_ft_lvec *sa_ra, size_t ra, size_t sa)
{
	sa_ra->data[ra] = StackRA;
	sa_ra->data[sa] = StackSA;
}

static size_t	index_of_last_movable_switch(const t_ft_lvec *sa_ra)
{
	size_t	i;

	i = sa_ra->length - 1;
	while (sa_ra->data[i] != StackSA)
		i--;
	while (i == sa_ra->length - 1
		|| (i != sa_ra->length - 2 && sa_ra->data[i + 2] == StackSA))
	{
		i--;
		while (sa_ra->data[i] != StackSA)
			i--;
	}
	return (i);
}

static void	collapse_next_switches(t_ft_lvec *sa_ra, size_t next_sa_idx)
{
	size_t	prev_sa_idx;

	prev_sa_idx = next_sa_idx;
	while (next_sa_idx < sa_ra->length && sa_ra->data[next_sa_idx] == StackRA)
		next_sa_idx++;
	while (next_sa_idx < sa_ra->length)
	{
		if (prev_sa_idx != next_sa_idx)
			swap_switch_rotate(sa_ra, next_sa_idx, prev_sa_idx);
		next_sa_idx += 2;
		prev_sa_idx = next_sa_idx;
		while (next_sa_idx < sa_ra->length
			&& sa_ra->data[next_sa_idx] == StackRA)
			next_sa_idx++;
	}
}

static void	make_next_sa_ra_combination(t_ft_lvec *sa_ra)
{
	size_t	last_movable_switch;

	last_movable_switch = index_of_last_movable_switch(sa_ra);
	swap_switch_rotate(sa_ra, last_movable_switch, last_movable_switch + 1);
	collapse_next_switches(sa_ra, last_movable_switch + 3);
}

int	try_sort_with_next_switches(t_ft_lvec *wrk_a, t_ft_lvec *sa_ra)
{
	size_t	i;

	make_next_sa_ra_combination(sa_ra);
	i = -1;
	while (++i < sa_ra->length)
	{
		if (sa_ra->data[i] == StackRA)
			stack_ra(wrk_a, NULL);
		else
			stack_sa(wrk_a, NULL);
	}
	return (0);
}
