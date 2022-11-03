/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_b_to_a.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:13:33 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 22:13:33 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EFFICIENT_B_TO_A_H
# define EFFICIENT_B_TO_A_H

size_t	compute_ra_count(
			const t_ft_lvec *stack_a,
			size_t min_val_idx,
			long new_elem
			);
int		rotate_a_to_match_b(
			t_ft_lvec *stack_a,
			long stack_b_front,
			t_ft_lvec *instructions
			);

#endif //EFFICIENT_B_TO_A_H
