/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:15:50 by aronez            #+#    #+#             */
/*   Updated: 2022/10/19 17:15:50 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEX_LIST_H
# define INDEX_LIST_H

#include <stddef.h>

typedef struct	s_index_list
{
	size_t	*indexes;
	size_t	length;
	size_t	capacity;
}	t_index_list;

void	free_index_list(t_index_list index_list);
int		index_list_new(t_index_list *index_list);

size_t	index_list_back(t_index_list index_list);

int	index_list_push_back(t_index_list *index_list, size_t index);

#endif //INDEX_LIST_H
