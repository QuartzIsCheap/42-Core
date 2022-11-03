/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_rotates_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:23:07 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:23:07 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../element_movements.h"

int	try_sort_with_only_rotates(
		t_ft_lvec *wrk_a,
		t_ft_lvec *sa_ra,
		size_t ra_count
		)
{
	size_t	i;

	i = -1;
	while (++i < ra_count)
	{
		if (ra_once(wrk_a, sa_ra) < 0)
			return (-1);
	}
	return (0);
}
