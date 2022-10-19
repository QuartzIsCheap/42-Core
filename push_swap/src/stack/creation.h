/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_CREATION_H
# define STACK_CREATION_H

# include "../stack.h"

int	try_parse_stack(int argc, char *argv[], t_stack *stack);
int	try_create_empty_stack(size_t capacity, t_stack *stack);

#endif //STACK_CREATION_H
