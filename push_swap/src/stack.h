/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:26:54 by aronez            #+#    #+#             */
/*   Updated: 2022/10/26 10:26:54 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

int		parse_args_into_stack(int argc, char *argv[], t_ft_lvec *stack);

void	stack_sa(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_sb(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_ss(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_pa(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_pb(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_ra(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_rb(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_rr(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_rra(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_rrb(t_ft_lvec *stack_a, t_ft_lvec *stack_b);
void	stack_rrr(t_ft_lvec *stack_a, t_ft_lvec *stack_b);

#endif //STACK_H
