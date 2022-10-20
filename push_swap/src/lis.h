/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:03:03 by aronez            #+#    #+#             */
/*   Updated: 2022/10/20 12:03:03 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIS_H
# define LIS_H

#include "stack.h"
#include "index_list.h"

int	find_lis_indexes(t_stack stack, t_index_list *lis);

#endif //LIS_H
