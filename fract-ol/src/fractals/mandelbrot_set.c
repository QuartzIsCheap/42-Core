/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:06:14 by aronez            #+#    #+#             */
/*   Updated: 2022/11/19 16:06:14 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "../fractals.h"

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

static size_t	mandelbrot_iterations(
		t_current_area zoom_state,
		t_pos pixel_pos
		)
{
	double	x;
	double	y;
	double	tmp;
	size_t	i;

	x = 0.0;
	y = 0.0;
	i = 0;
	while (i < 1000 && x * x + y * y < 2.0 * 2.0)
	{
		tmp = x * x - y * y
			+ (zoom_state.x + pixel_pos.x * zoom_state.width) * 2.47 - 2.0;
		y = 2 * x * y + (zoom_state.y + pixel_pos.y * zoom_state.height)
			* 2.24 - 1.12;
		x = tmp;
		i += STEP;
	}
	return (i);
}

void	fill_with_mandelbrot_set(
			const t_img *img,
			t_current_area zoom_state,
			void *set_parameters
			)
{
	char							*data;
	const t_mandelbrot_parameters	*mandelbrot_parameters;
	t_img_layout					img_layout;
	int								i;
	int								j;

	data = mlx_get_data_addr(
			img->img_ptr, &img_layout.bits_per_pixel,
			&img_layout.size_line, &img_layout.endian
			);
	mandelbrot_parameters = (const t_mandelbrot_parameters *)set_parameters;
	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width)
			((u_int32_t *)data)[i * img->width + j]
				= mandelbrot_parameters->palette[mandelbrot_iterations(
					zoom_state,
					(t_pos){(double)j / img->width, (double)i / img->height}
					)];
	}
}
