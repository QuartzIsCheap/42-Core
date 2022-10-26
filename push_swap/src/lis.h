/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:12:56 by aronez            #+#    #+#             */
/*   Updated: 2022/10/26 15:12:56 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIS_H
# define LIS_H

int	find_rotated_longest_lis(const t_ft_lvec *vec, t_ft_svec *lis);
int	find_lis_indexes(const t_ft_lvec *vec, t_ft_svec *lis);

#endif //LIS_H
