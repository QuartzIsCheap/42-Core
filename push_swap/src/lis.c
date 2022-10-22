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

size_t	find_min_index(t_stack stk, t_index_list prev_idxs)
{
	size_t	idx, min_idx;
	int		prv_min, occurrence_found;

	if (prev_idxs.length == 0)
		prv_min = -1;
	else
		prv_min = stk.data[prev_idxs.indexes[0]];
	occurrence_found = 0;
	idx = 0;
	min_idx = 0;
	while (idx < stk.length)
	{
		if (!index_list_contains(prev_idxs, idx))
		{
			if (prv_min < stk.data[idx] && stk.data[idx] <= stk.data[min_idx])
			{
				min_idx = idx;
				occurrence_found = 1;
			}
		}
		idx++;
	}
	if (!occurrence_found)
		return (stk.length);
	return (min_idx);
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

int	try_next_lis(t_stack stack, t_index_list *lis)
{
	t_index_list	new_lis;
	size_t			min_index;
	int				status;

	min_index = find_min_index(stack, *lis);
	if (min_index == stack.length)
		return (0);
	if (index_list_new(&new_lis) < 0)
		return (-1);
	if (index_list_push_back(&new_lis, min_index) < 0)
		return (index_list_free(new_lis), -1);
	if (append_larger_elements(stack, &new_lis, new_lis.indexes[0]) < 0)
		return (-1);
	status = 1;
	while (status > 0)
	{
		if (index_list_assign(new_lis, lis) < 0)
			return (index_list_free(new_lis), -1);
		status = extend_lis(stack, &new_lis);
	}
	if (status < 0)
		return (status);
	return (index_list_free(new_lis), 1);
}

int	find_lis_indexes(t_stack stack, t_index_list *lis)
{
	t_index_list	new_lis;
	int				new_lis_status;

	if (index_list_new(lis) < 0)
		return (-1);
	if (index_list_new(&new_lis) < 0)
		return (index_list_free(*lis), -1);
	new_lis_status = try_next_lis(stack, &new_lis);
	while (new_lis_status > 0)
	{
		if (new_lis.length > lis->length)
		{
			if (index_list_assign(new_lis, lis) < 0)
				return (index_list_free(new_lis), -1);
		}
		new_lis_status = try_next_lis(stack, &new_lis);
	}
	index_list_free(new_lis);
	if (new_lis_status < 0)
		return (index_list_free(*lis), -1);
	return (0);
}
