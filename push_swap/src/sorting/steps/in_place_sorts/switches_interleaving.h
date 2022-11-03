/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches_interleaving.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:37:30 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:37:30 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWITCHES_INTERLEAVING_H
# define SWITCHES_INTERLEAVING_H

int	try_sort_with_begin_switches(
		t_ft_lvec *wrk_a,
		t_ft_lvec *sa_ra,
		size_t ra_count,
		size_t sa_count
		);
int	try_sort_with_next_switches(t_ft_lvec *wrk_a, t_ft_lvec *sa_ra);

#endif //SWITCHES_INTERLEAVING_H
