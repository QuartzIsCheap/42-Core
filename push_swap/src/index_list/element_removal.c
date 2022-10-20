/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_removal.c                                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:00:35 by aronez            #+#    #+#             */
/*   Updated: 2022/10/19 19:00:35 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index_list.h"

size_t	index_list_pop(t_index_list *index_list)
{
	size_t	last_index;

	if (index_list->length == 0)
		return (0);
	last_index = index_list_back(*index_list);
	index_list->length--;
	return (last_index);
}
