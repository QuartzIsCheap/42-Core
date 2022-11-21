/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:37:46 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 13:37:46 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "mlx.h"

#include "../../fractals.h"

#include "../../mlx_img.h"
#include "../../zoom.h"

typedef struct s_img_layout
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}	t_img_layout;

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

static size_t	julia_iterations(
		const t_julia_parameters *julia_parameters,
		t_current_area zoom_state,
		t_pos pixel_pos
		)
{
	double		zx;
	double		zy;
	double		tmp;
	size_t		i;

	zx = (zoom_state.x + pixel_pos.x * zoom_state.width) * 3.0 - 1.5;
	zy = (zoom_state.y + pixel_pos.y * zoom_state.height) * 3.0 - 1.5;
	i = 0;
	while (i < 1000 && zx * zx + zy * zy < 1.5 * 1.5)
	{
		tmp = zx * zx - zy * zy;
		zy = 2 * zx * zy + julia_parameters->cy;
		zx = tmp + julia_parameters->cx;
		i += STEP;
	}
	return (i);
}

void	fill_with_julia_set(
		const t_img *img,
		t_current_area zoom_state,
		void *set_parameters
		)
{
	char						*data;
	const t_julia_parameters	*julia_parameters;
	t_img_layout				img_layout;
	int							i;
	int							j;

	data = mlx_get_data_addr(
			img->img_ptr, &img_layout.bits_per_pixel,
			&img_layout.size_line, &img_layout.endian
			);
	julia_parameters = (const t_julia_parameters *)set_parameters;
	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width)
			((u_int32_t *)data)[i * img->width + j]
				= julia_parameters->palette[julia_iterations(
					julia_parameters, zoom_state,
					(t_pos){(double)j / img->width, (double)i / img->height}
					)];
	}
}
