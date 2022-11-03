/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_to_match_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:28:53 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 17:28:53 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../efficient_b_to_a.h"
#include "../../sorted_stack_lookup.h"
#include "../../element_movements.h"

int	rotate_a_to_match_b(
		t_ft_lvec *stack_a,
		long stack_b_front,
		t_ft_lvec *instructions
		)
{
	size_t	ra_count_to_fit_front_b;

	ra_count_to_fit_front_b = compute_ra_count(
			stack_a, index_of_min_a_value(stack_a), stack_b_front
			);
	if (rotate_a_efficiently(
			stack_a, instructions, ra_count_to_fit_front_b
		) < 0)
		return (-1);
	return (0);
}
