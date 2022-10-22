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

void	index_list_free(t_index_list index_list);
int		index_list_new(t_index_list *index_list);
int		index_list_copy(t_index_list src, t_index_list *dst);
int		index_list_assign(t_index_list src, t_index_list *dst);

size_t	index_list_back(t_index_list index_list);
size_t	index_list_front(t_index_list index_list);
int		index_list_contains(t_index_list index_list, size_t index);

int		index_list_push_back(t_index_list *index_list, size_t index);

size_t	index_list_pop(t_index_list *index_list);

#endif //INDEX_LIST_H
