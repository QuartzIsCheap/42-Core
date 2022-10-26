/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:33:07 by aronez            #+#    #+#             */
/*   Updated: 2022/10/26 16:33:07 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "libft.h"

#include "../lis.h"
#include "../stack.h"

static void	free_candidates(t_ft_svec *candidates, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		ft_svec_free(candidates + i);
		i++;
	}
}

static int	generate_lis_candidates(
		const t_ft_lvec *vec,
		t_ft_svec *lis_candidates
		)
{
	t_ft_lvec	rotated_vec;
	size_t		i;

	if (ft_lvec_clone(vec, &rotated_vec) < 0)
		return (-1);
	i = 0;
	while (i < vec->length)
	{
		if (find_lis_indexes(&rotated_vec, lis_candidates + i) < 0)
			return (free_candidates(lis_candidates, i), -1);
		stack_ra(&rotated_vec, NULL);
		i++;
	}
	ft_lvec_free(&rotated_vec);
	return (0);
}

static size_t	find_longest_lis_idx(t_ft_svec *svecs, size_t svecs_count)
{
	size_t	i;
	size_t	max_idx;

	i = 0;
	max_idx = 0;
	while (i < svecs_count)
	{
		if (svecs[i].length > svecs[max_idx].length)
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	find_rotated_longest_lis(
		const t_ft_lvec *vec,
		t_ft_svec *lis,
		size_t *ra_count
)
{
	t_ft_svec	*lis_candidates;
	size_t		longest_lis_idx;
	int			lis_clone_status;

	lis_candidates = malloc(sizeof(t_ft_svec) * vec->length);
	if (lis_candidates == NULL)
		return (-1);
	if (generate_lis_candidates(vec, lis_candidates) < 0)
		return (free(lis_candidates), -1);
	longest_lis_idx = find_longest_lis_idx(lis_candidates, vec->length);
	lis_clone_status = ft_svec_clone(lis_candidates + longest_lis_idx, lis);
	free_candidates(lis_candidates, vec->length);
	free(lis_candidates);
	if (lis_clone_status < 0)
		return (-1);
	*ra_count = longest_lis_idx;
	return (0);
}
