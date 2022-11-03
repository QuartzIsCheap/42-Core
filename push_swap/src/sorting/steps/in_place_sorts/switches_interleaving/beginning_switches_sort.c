/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginning_switches_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:39:40 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:39:40 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../../element_movements.h"

int	try_sort_with_begin_switches(
		t_ft_lvec *wrk_a,
		t_ft_lvec *sa_ra,
		size_t ra_count,
		size_t sa_count
)
{
	size_t	i;

	if (sa_once(wrk_a, sa_ra) < 0)
		return (-1);
	i = -1;
	while (++i < ft_smax(ra_count, sa_count - 1))
	{
		if (i < ra_count)
		{
			if (ra_once(wrk_a, sa_ra) < 0)
				return (-1);
		}
		if (i < sa_count - 1)
		{
			if (sa_once(wrk_a, sa_ra) < 0)
				return (-1);
		}
	}
	return (0);
}
