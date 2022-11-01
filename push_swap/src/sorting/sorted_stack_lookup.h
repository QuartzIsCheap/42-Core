/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack_lookup.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:10:07 by aronez            #+#    #+#             */
/*   Updated: 2022/10/28 15:10:07 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTED_STACK_LOOKUP_H
# define SORTED_STACK_LOOKUP_H

# include <libft.h>

size_t	index_of_min_a_value(const t_ft_lvec *stack_a);
size_t	index_of_min_b_value(const t_ft_lvec *stack_b);
size_t	index_of_max_a_value(const t_ft_lvec *stack_a);

#endif //SORTED_STACK_LOOKUP_H
