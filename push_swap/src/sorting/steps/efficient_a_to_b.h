/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_a_to_b.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:23:01 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 16:23:01 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EFFICIENT_A_TO_B_H
# define EFFICIENT_A_TO_B_H

# include <libft.h>

size_t	compute_rb_count(
			const t_ft_lvec *stack_b,
			size_t min_val_idx,
			long new_elem
			);
size_t	find_min_cost_elem(
			const t_ft_lvec *stack_a,
			const t_ft_lvec *stack_b,
			t_ft_svec *lis,
			size_t min_val_b_idx
			);
size_t	first_non_lis_elem_idx(size_t stack_a_length, const t_ft_svec *lis);

#endif //EFFICIENT_A_TO_B_H
