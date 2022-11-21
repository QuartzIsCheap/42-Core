/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:46:50 by aronez            #+#    #+#             */
/*   Updated: 2022/10/25 09:46:50 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>

#include "fractals.h"
#include "mlx_setup.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

static void	plug_mandelbrot(
		t_mlx_loop_objs *loop_objs,
		t_mandelbrot_parameters *mandelbrot_parameters
		)
{
	loop_objs->img_writer = &fill_with_mandelbrot_set;
	generate_palette(mandelbrot_parameters->palette);
	loop_objs->set_parameters = mandelbrot_parameters;
}

static void	plug_julia_sets(
		t_mlx_loop_objs *loop_objs,
		t_julia_parameters *julia_parameters
		)
{
	loop_objs->img_writer = &fill_with_julia_set;
	generate_palette(julia_parameters->palette);
	loop_objs->set_parameters = julia_parameters;
}

static void	display_help(void)
{
	ft_printf("Fractol usage :\n");
	ft_printf("\t- The first argument is the set. Type 1 for the Mandelbrot ");
	ft_printf("set, 2 for a Julia set.\n");
	ft_printf("\t- For Julia sets, please specify the c complex parameter as ");
	ft_printf("two doubles in the [-1.0, 1.0] range.\n");
}

int	main(int argc, char *argv[])
{
	int						set_idx;
	t_mandelbrot_parameters	mandelbrot_parameters;
	t_julia_parameters		julia_parameters;
	t_mlx_loop_objs			loop_objs;

	if (argc == 2 && ft_s_atoi(argv[1], &set_idx) == 0 && set_idx == 1)
		plug_mandelbrot(&loop_objs, &mandelbrot_parameters);
	else if (argc == 4 && ft_s_atoi(argv[1], &set_idx) == 0 && set_idx == 2
		&& try_parse_julia_parameters(argv + 2, &julia_parameters) == 0)
		plug_julia_sets(&loop_objs, &julia_parameters);
	else
	{
		display_help();
		return (EXIT_SUCCESS);
	}
	loop_objs.window_area = (t_window_area){WIN_WIDTH, WIN_HEIGHT};
	if (init_mlx_objs(&loop_objs) < 0)
		return (EXIT_FAILURE);
	setup_controller_hooks(&loop_objs);
	mlx_loop(loop_objs.mlx_ptr);
	destroy_mlx_objs(&loop_objs);
	return (EXIT_SUCCESS);
}
