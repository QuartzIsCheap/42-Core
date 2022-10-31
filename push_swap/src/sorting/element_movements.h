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

int	push_to_a(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
		);
int	push_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions,
		t_ft_svec *lis
		);

int	rotate_a_efficiently(
		t_ft_lvec *stack_a,
		t_ft_lvec *instructions,
		t_ft_svec *lis,
		size_t ra_count
		);
int	rotate_b_efficiently(
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions,
		size_t rb_count
		);

#endif //ELEMENT_MOVEMENTS_H
