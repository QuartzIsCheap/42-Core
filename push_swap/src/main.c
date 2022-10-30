/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:46:50 by aronez            #+#    #+#             */
/*   Updated: 2022/10/25 09:46:50 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "instructions.h"
#include "lis.h"
#include "stack.h"
#include "sorting.h"

void	display_instructions(const t_ft_lvec *instructions)
{
	size_t	i;

	i = 0;
	while (i < instructions->length)
	{
		if (instructions->data[i] == StackRA)
			ft_printf("ra\n");
		else if (instructions->data[i] == StackRB)
			ft_printf("rb\n");
		else if (instructions->data[i] == StackRRA)
			ft_printf("rra\n");
		else if (instructions->data[i] == StackRRB)
			ft_printf("rrb\n");
		else if (instructions->data[i] == StackPA)
			ft_printf("pa\n");
		else if (instructions->data[i] == StackPB)
			ft_printf("pb\n");
		else if (instructions->data[i] == StackRR)
			ft_printf("rr\n");
		else if (instructions->data[i] == StackRRR)
			ft_printf("rrr\n");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_ft_lvec	stack_a;
	t_ft_svec	lis;
	t_ft_lvec	instructions;

	if (parse_args_into_stack(argc, argv, &stack_a) < 0)
		return (EXIT_FAILURE);
	if (stack_a.length < 2)
		return (EXIT_SUCCESS);
	if (find_rotated_longest_lis(&stack_a, &lis) < 0)
		return (ft_lvec_free(&stack_a), EXIT_FAILURE);
	if (ft_lvec_new(&instructions) < 0)
		return (ft_svec_free(&lis), ft_lvec_free(&stack_a), EXIT_FAILURE);
	if (sort_stack(&stack_a, &lis, &instructions) < 0)
		return (ft_svec_free(&lis), ft_lvec_free(&stack_a), EXIT_FAILURE);
	compress_instructions(&instructions);
	display_instructions(&instructions);
	ft_lvec_free(&instructions);
	return (ft_lvec_free(&stack_a), ft_svec_free(&lis), EXIT_SUCCESS);
}
