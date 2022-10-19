/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:17:48 by aronez            #+#    #+#             */
/*   Updated: 2022/10/19 17:17:48 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

#include "../index_list.h"

void	free_index_list(t_index_list index_list)
{
	free(index_list.indexes);
}

int	index_list_new(t_index_list *index_list)
{
	index_list->length = 0;
	index_list->capacity = 10;
	index_list->indexes = ft_calloc(10, sizeof(size_t));
	if (index_list->indexes == NULL)
		return (-1);
	return (0);
}
