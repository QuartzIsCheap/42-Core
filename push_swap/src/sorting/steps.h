/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:09:19 by aronez            #+#    #+#             */
/*   Updated: 2022/10/31 11:09:19 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STEPS_H
# define STEPS_H

# include <libft.h>

int	push_non_lis_elems_to_b(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_svec *lis,
		t_ft_lvec *instructions
		);
int	push_b_back_to_a(
		t_ft_lvec *stack_a,
		t_ft_lvec *stack_b,
		t_ft_lvec *instructions
		);

#endif //STEPS_H
