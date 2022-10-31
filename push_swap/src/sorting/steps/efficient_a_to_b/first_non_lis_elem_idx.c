/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_non_lis_elem_idx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:18:36 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 16:18:36 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	first_non_lis_elem_idx(size_t stack_a_length, const t_ft_svec *lis)
{
	size_t	i;

	i = 0;
	while (i < stack_a_length)
	{
		if (!ft_svec_contains(lis, i))
			return (i);
		i++;
	}
	return (0);
}
