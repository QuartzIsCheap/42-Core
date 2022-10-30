/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_movements.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:18:21 by aronez            #+#    #+#             */
/*   Updated: 2022/10/28 10:18:21 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_MOVEMENTS_H
# define ELEMENT_MOVEMENTS_H

int	ra_once(t_ft_lvec *stack_a, t_ft_svec *lis, t_ft_lvec *instructions);
int	pb_with_sorting_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
		);
int	pa_until_next_lis_elem(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
		);
int	rra_until_front_b_fits_a(
		t_ft_lvec *stack_a,
		long stack_b_front,
		t_ft_lvec *instructions
		);
int	rra_sorted_a_until_main(t_ft_lvec *stack_a, t_ft_lvec *instructions);
int	rrb_sorted_b_until_main(t_ft_lvec *stack_b, t_ft_lvec *instructions);

#endif //ELEMENT_MOVEMENTS_H
