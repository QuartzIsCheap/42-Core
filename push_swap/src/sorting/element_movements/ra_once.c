/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_once.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:20:09 by aronez            #+#    #+#             */
/*   Updated: 2022/10/28 10:20:09 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "../../stack.h"
#include "../../lis.h"

int	ra_once(t_ft_lvec *stack_a, t_ft_svec *lis, t_ft_lvec *instructions)
{
	stack_ra(stack_a, NULL);
	if (ft_lvec_push_back(instructions, StackRA) < 0)
		return (-1);
	offset_lis(lis, -1, stack_a->length);
	return (0);
}
