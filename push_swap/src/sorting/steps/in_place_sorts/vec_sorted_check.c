/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sorted_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:28:58 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:28:58 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	is_vec_sorted(const t_ft_lvec *lvec)
{
	size_t	i;

	i = 0;
	while (i < lvec->length - 1)
	{
		if (lvec->data[i] > lvec->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
