/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.c                                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:38:22 by aronez            #+#    #+#             */
/*   Updated: 2022/10/19 17:38:22 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../index_list.h"

size_t	index_list_back(t_index_list index_list)
{
	if (index_list.length == 0)
		return (0);
	return (index_list.indexes[index_list.length - 1]);
}
