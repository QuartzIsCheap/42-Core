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

int	push_to_a(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
		);
int	push_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
		);

int	rotate_a_efficiently(
		t_ft_lvec *stack_a,
		t_ft_lvec *instructions,
		size_t ra_count
		);
int	rotate_b_efficiently(
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions,
		size_t rb_count
		);

int	sa_once(t_ft_lvec *stack, t_ft_lvec *instructions);
int	ra_once(t_ft_lvec *stack, t_ft_lvec *instructions);

#endif //ELEMENT_MOVEMENTS_H
