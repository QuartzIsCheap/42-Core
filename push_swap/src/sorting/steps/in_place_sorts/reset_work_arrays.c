/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_work_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:15:17 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:15:17 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	reset_work_arrays(
		const t_ft_lvec *stack_a,
		t_ft_lvec *wrk_a,
		t_ft_lvec *sa_ra
		)
{
	if (ft_lvec_assign(stack_a, wrk_a) < 0)
		return (ft_lvec_free(sa_ra), -1);
	sa_ra->length = 0;
	return (0);
}
