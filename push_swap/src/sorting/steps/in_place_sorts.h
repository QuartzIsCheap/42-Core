/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_place_sorts.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:16:13 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 10:16:13 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_PLACE_SORTS_H
# define IN_PLACE_SORTS_H

int		is_vec_sorted(const t_ft_lvec *lvec);

int		reset_work_arrays(
			const t_ft_lvec *stack_a,
			t_ft_lvec *wrk_a,
			t_ft_lvec *sa_ra
			);

int		try_sort_with_only_rotates(
			t_ft_lvec *wrk_a,
			t_ft_lvec *sa_ra,
			size_t ra_count
			);
int		try_sort_with_switches(
			const t_ft_lvec *stack_a,
			t_ft_lvec *wrk_a,
			t_ft_lvec *sa_ra,
			size_t ra_count
			);

void	compress_rotates(t_ft_lvec *sa_ra, size_t stack_len);

#endif //IN_PLACE_SORTS_H
