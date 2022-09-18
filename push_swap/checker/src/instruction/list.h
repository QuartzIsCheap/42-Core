/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../stack.h"

void	stack_sa(t_stack *stack_a, t_stack *stack_b);
void	stack_sb(t_stack *stack_a, t_stack *stack_b);
void	stack_ss(t_stack *stack_a, t_stack *stack_b);
void	stack_pa(t_stack *stack_a, t_stack *stack_b);
void	stack_pb(t_stack *stack_a, t_stack *stack_b);
void	stack_ra(t_stack *stack_a, t_stack *stack_b);
void	stack_rb(t_stack *stack_a, t_stack *stack_b);
void	stack_rr(t_stack *stack_a, t_stack *stack_b);
void	stack_rra(t_stack *stack_a, t_stack *stack_b);
void	stack_rrb(t_stack *stack_a, t_stack *stack_b);
void	stack_rrr(t_stack *stack_a, t_stack *stack_b);

#endif //LIST_H
