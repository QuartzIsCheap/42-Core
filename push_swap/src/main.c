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

#include "stack.h"

int	main(int argc, char *argv[])
{
	t_ft_lvec	stack_a;

	if (parse_args_into_stack(argc, argv, &stack_a) < 0)
		return (EXIT_FAILURE);
	for (size_t i = 0; i < stack_a.length; ++i)
	{
		ft_printf("%i ", stack_a.data[i]);
	}
	ft_printf("\n");
	ft_lvec_free(&stack_a);
	return (EXIT_SUCCESS);
}
