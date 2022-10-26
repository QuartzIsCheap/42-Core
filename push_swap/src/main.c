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
#include "libft.h"

#include "lis.h"
#include "stack.h"

int	main(int argc, char *argv[])
{
	t_ft_lvec	stack_a;
	t_ft_svec	lis;

	if (parse_args_into_stack(argc, argv, &stack_a) < 0)
		return (EXIT_FAILURE);

	for (size_t i = 0; i < stack_a.length; ++i)
	{
		ft_printf("%i ", stack_a.data[i]);
	}
	ft_printf("\n");

	if (find_lis_indexes(&stack_a, &lis) < 0)
		return (ft_lvec_free(&stack_a), EXIT_FAILURE);

	for (size_t i = 0; i < lis.length; ++i)
	{
		ft_printf("%i[%u] ", stack_a.data[lis.data[i]], lis.data[i]);
	}
	ft_printf("\n");

	return (ft_lvec_free(&stack_a), ft_svec_free(&lis), EXIT_SUCCESS);
}
