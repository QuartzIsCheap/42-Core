/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:24:20 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:24:20 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../stack.h"

int	sa_once(t_ft_lvec *stack, t_ft_lvec *instructions)
{
	stack_sa(stack, NULL);
	if (ft_lvec_push_back(instructions, StackSA) < 0)
		return (-1);
	return (0);
}

int	ra_once(t_ft_lvec *stack, t_ft_lvec *instructions)
{
	stack_ra(stack, NULL);
	if (ft_lvec_push_back(instructions, StackRA) < 0)
		return (ft_lvec_free(stack), -1);
	return (0);
}
