/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:54:49 by aronez            #+#    #+#             */
/*   Updated: 2022/11/19 15:54:49 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "../fractals.h"

static u_int32_t	gradient(size_t i, double start, double end, u_int32_t grad)
{
	return ((u_int32_t)(((double)i - start) / (end - start) * grad));
}

void	generate_palette(u_int32_t palette[1000])
{
	size_t	i;

	i = -1;
	while (++i < 1000)
	{
		if ((double)i <= B1)
			palette[i] = (0x40 + gradient(i, B0, B1, 0x10)) << (8 * 0);
		else if ((double)i <= B2)
			palette[i] = (0x50 + gradient(i, B1, B2, 0x9f)) << (8 * 0)
				| (0x00 + gradient(i, B1, B2, 0x88)) << (8 * 1)
				| (0x00 + gradient(i, B1, B2, 0x44)) << (8 * 2);
		else if ((double)i <= B3)
			palette[i] = (0xef - gradient(i, B2, B3, 0x44)) << (8 * 0)
				| (0x88 + gradient(i, B2, B3, 0x33)) << (8 * 1)
				| (0x44 + gradient(i, B2, B3, 0x88)) << (8 * 2);
		else if ((double)i <= B4)
			palette[i] = (0xab - gradient(i, B3, B4, 0x55)) << (8 * 0)
				| (0xbb - gradient(i, B3, B4, 0x33)) << (8 * 1)
				| (0xcc - gradient(i, B3, B4, 0x22)) << (8 * 2);
		else if ((double)i <= B5)
			palette[i] = (0x4d) << (8 * 0)
				| (0x8f) << (8 * 1)
				| (0xaa) << (8 * 2);
		palette[i] |= ((u_int32_t)(1 * 0xff) << (8 * 3));
	}
}
