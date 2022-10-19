/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_adding.c                                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:37:10 by aronez            #+#    #+#             */
/*   Updated: 2022/10/19 17:37:10 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index_list.h"

#include "libft.h"

int	index_list_push_back(t_index_list *index_list, size_t index)
{
	if (index_list->length == index_list->capacity)
	{
		index_list->indexes = ft_realloc(
				index_list->indexes,
				sizeof(size_t) * index_list->capacity,
				sizeof(size_t) * ft_smin(index_list->capacity, 10240)
		);
		if (index_list->indexes == NULL)
			return (-1);
		index_list->capacity += ft_smin(index_list->capacity, 10240);
	}
	index_list->indexes[index_list->length] = index;
	index_list->length++;
	return (0);
}
