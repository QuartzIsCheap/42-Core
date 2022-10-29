/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:43:13 by aronez            #+#    #+#             */
/*   Updated: 2022/10/27 18:43:13 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	offset_lis(t_ft_svec *lis, long offset, size_t stack_len)
{
	size_t	i;
	long	new_idx;

	i = 0;
	while (i < lis->length)
	{
		new_idx = ((long)lis->data[i] + offset) % (long)stack_len;
		if (new_idx < 0)
			new_idx += (long)stack_len;
		lis->data[i] = new_idx;
		i++;
	}
}
