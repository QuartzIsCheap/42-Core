/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:34:10 by aronez            #+#    #+#             */
/*   Updated: 2022/09/18 12:34:10 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct	s_stack
{
	int		*data;
	size_t	capacity;
	size_t	length;
}	t_stack;

void	free_stack(t_stack stack);

#endif //STACK_H
