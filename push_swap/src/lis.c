/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:04:14 by aronez            #+#    #+#             */
/*   Updated: 2022/10/20 12:04:14 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lis.h"

#include <stddef.h>

#include "stack.h"
#include "index_list.h"

size_t	find_min_index(t_stack stack)
{
	size_t	index;
	size_t	min_index;

	index = 0;
	min_index = index;
	while (index < stack.length)
	{
		if (stack.data[index] < stack.data[min_index])
			min_index = index;
		index++;
	}
	return (min_index);
}

int	append_larger_elements(
		t_stack stack,
		t_index_list *lis,
		size_t index_from
)
{
	size_t	index;

	index = index_from;
	if (index_list_front(*lis) < index + 1)
	{
		while (++index < stack.length)
		{
			if (stack.data[index] > stack.data[index_list_back(*lis)])
			{
				if (index_list_push_back(lis, index) < 0)
					return (-1);
			}
		}
		index = -1;
	}
	while (++index < index_list_front(*lis))
	{
		if (stack.data[index] > stack.data[index_list_back(*lis)])
		{
			if (index_list_push_back(lis, index) < 0)
				return (-1);
		}
	}
	return (0);
}

int	extend_lis(t_stack stack, t_index_list *lis)
{
	t_index_list	mem_lis;
	size_t			mem_length;

	if (index_list_copy(*lis, &mem_lis) < 0)
		return (-1);
	mem_length = lis->length;
	while (lis->length != 1)
	{
		index_list_pop(&mem_lis);
		if (append_larger_elements(
				stack,
				lis,
				index_list_pop(lis)
				) < 0)
			return (index_list_free(mem_lis), -1);
		if (lis->length > mem_length)
			return (index_list_free(mem_lis), 1);
		if (lis->length > mem_lis.length)
		{
			if (index_list_assign(*lis, &mem_lis) < 0)
				return (index_list_free(mem_lis), -1);
		}
		else if (index_list_assign(mem_lis, lis) < 0)
			return (-1);
	}
	return (index_list_free(mem_lis), 0);
}

int	find_lis_indexes(t_stack stack, t_index_list *lis)
{
	t_index_list	new_lis;
	int				new_lis_status;

	if (index_list_new(&new_lis) < 0)
		return (-1);
	if (index_list_push_back(&new_lis, find_min_index(stack)) < 0)
		return (index_list_free(new_lis), -1);
	if (append_larger_elements(stack, &new_lis, new_lis.indexes[0]) < 0)
		return (-1);
	if (index_list_new(lis) < 0)
		return (index_list_free(new_lis), -1);
	new_lis_status = 1;
	while (new_lis_status > 0)
	{
		if (index_list_assign(new_lis, lis) < 0)
			return (index_list_free(new_lis), -1);
		new_lis_status = extend_lis(stack, &new_lis);
	}
	index_list_free(new_lis);
	if (new_lis_status < 0)
		return (index_list_free(*lis), -1);
	return (0);
}
