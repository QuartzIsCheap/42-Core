/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_lookup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:44:52 by aronez            #+#    #+#             */
/*   Updated: 2022/10/21 17:44:52 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index_list.h"

int	index_list_contains(t_index_list index_list, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index_list.length)
	{
		if (index_list.indexes[i] == index)
			return (1);
		i++;
	}
	return (0);
}
