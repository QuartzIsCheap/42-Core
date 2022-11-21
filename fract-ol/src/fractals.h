/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:29:26 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 13:29:26 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include <sys/types.h>

# include "mlx_img.h"
# include "zoom.h"

# define STEP 2
# define B0 0000.0
# define B1 0150.0
# define B2 0450.0
# define B3 0800.0
# define B4 0950.0
# define B5 1000.0

typedef struct s_julia_parameters
{
	double		cx;
	double		cy;
	u_int32_t	palette[1000];
}	t_julia_parameters;

typedef struct s_mandelbrot_parameters
{
	u_int32_t	palette[1000];
}	t_mandelbrot_parameters;

void	generate_palette(u_int32_t palette[1000]);

int		try_parse_julia_parameters(
			char *parameters_str[],
			t_julia_parameters *julia_parameters
			);
void	fill_with_julia_set(
			const t_img *img,
			t_current_area zoom_state,
			void *set_parameters
			);

void	fill_with_mandelbrot_set(
			const t_img *img,
			t_current_area zoom_state,
			void *set_parameters
			);

#endif //FRACTALS_H
