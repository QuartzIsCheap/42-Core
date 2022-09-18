/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../instruction.h"
#include "list.h"

int		try_parse_instruction(const char *str, t_instruction *instruction)
{
	if (ft_strcmp(str, "sa\n") == 0)
		*instruction = &stack_sa;
	else if (ft_strcmp(str, "sb\n") == 0)
		*instruction = &stack_sb;
	else if (ft_strcmp(str, "ss\n") == 0)
		*instruction = &stack_ss;
	else if (ft_strcmp(str, "pa\n") == 0)
		*instruction = &stack_pa;
	else if (ft_strcmp(str, "pb\n") == 0)
		*instruction = &stack_pb;
	else if (ft_strcmp(str, "ra\n") == 0)
		*instruction = &stack_ra;
	else if (ft_strcmp(str, "rb\n") == 0)
		*instruction = &stack_rb;
	else if (ft_strcmp(str, "rr\n") == 0)
		*instruction = &stack_rr;
	else if (ft_strcmp(str, "rra\n") == 0)
		*instruction = &stack_rra;
	else if (ft_strcmp(str, "rrb\n") == 0)
		*instruction = &stack_rrb;
	else if (ft_strcmp(str, "rrr\n") == 0)
		*instruction = &stack_rrr;
	else
		return (-1);
	return (0);
}
