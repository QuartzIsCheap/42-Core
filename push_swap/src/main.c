/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "index_list.h"
#include "lis.h"
#include "stack.h"
#include "stack/creation.h"

int main(int argc, char *argv[])
{
	t_stack			stack;
	t_index_list	lis_indexes;

	if (try_parse_stack(argc, argv, &stack) < 0)
	{
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	if (find_lis_indexes(stack, &lis_indexes) < 0)
		return (free_stack(stack), EXIT_FAILURE);
	
	return (index_list_free(lis_indexes), free_stack(stack), EXIT_SUCCESS);
}
