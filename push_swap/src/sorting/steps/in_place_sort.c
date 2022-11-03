/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_place_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:09:27 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:09:27 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "in_place_sorts.h"

static int	find_fastest_sort(
		const t_ft_lvec *stack_a,
		t_ft_lvec *wrk_a,
		t_ft_lvec *sa_ra
		)
{
	size_t	ra_count;

	ra_count = -1;
	while (!is_vec_sorted(wrk_a) && ++ra_count < stack_a->length)
	{
		if (reset_work_arrays(stack_a, wrk_a, sa_ra) < 0)
			return (-1);
		if (try_sort_with_only_rotates(wrk_a, sa_ra, ra_count) < 0)
			return (-1);
	}
	ra_count = 0;
	while (!is_vec_sorted(wrk_a))
	{
		if (reset_work_arrays(stack_a, wrk_a, sa_ra) < 0)
			return (-1);
		if (try_sort_with_switches(stack_a, wrk_a, sa_ra, ra_count) < 0)
			return (-1);
		ra_count++;
	}
	return (0);
}

static int	append_instructions(t_ft_lvec *instructions, const t_ft_lvec *sa_ra)
{
	size_t	i;

	i = -1;
	while (++i < sa_ra->length)
	{
		if (ft_lvec_push_back(instructions, sa_ra->data[i]) < 0)
			return (-1);
	}
	return (0);
}

int	sort_in_place(t_ft_lvec *stack_a, t_ft_lvec *instructions)
{
	t_ft_lvec	wrk_a;
	t_ft_lvec	sa_ra;

	if (ft_lvec_clone(stack_a, &wrk_a) < 0)
		return (ft_lvec_free(stack_a), ft_lvec_free(instructions), -1);
	if (ft_lvec_new(&sa_ra) < 0)
		return (ft_lvec_free(&wrk_a), ft_lvec_free(stack_a),
			ft_lvec_free(instructions), -1);
	if (find_fastest_sort(stack_a, &wrk_a, &sa_ra) < 0)
		return (ft_lvec_free(instructions), -1);
	compress_rotates(&sa_ra, stack_a->length);
	if (ft_lvec_assign(&wrk_a, stack_a) < 0)
		return (ft_lvec_free(&sa_ra), ft_lvec_free(&wrk_a),
			ft_lvec_free(instructions), -1);
	if (append_instructions(instructions, &sa_ra) < 0)
		return (ft_lvec_free(&sa_ra), ft_lvec_free(&wrk_a),
			ft_lvec_free(stack_a), -1);
	return (ft_lvec_free(&sa_ra), ft_lvec_free(&wrk_a), 0);
}
