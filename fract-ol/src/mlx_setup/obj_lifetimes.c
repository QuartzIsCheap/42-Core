/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lifetimes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:08:21 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 11:08:21 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <mlx.h>

#include "../mlx_setup.h"
#include "../zoom.h"

int	init_mlx_objs(t_mlx_loop_objs *loop_objs)
{
	loop_objs->mlx_ptr = mlx_init();
	if (loop_objs->mlx_ptr == NULL)
		return (-1);
	loop_objs->win_ptr = mlx_new_window(loop_objs->mlx_ptr,
			loop_objs->window_area.width, loop_objs->window_area.height,
			"fract-ol");
	if (loop_objs->win_ptr == NULL)
		return (mlx_destroy_display(loop_objs->mlx_ptr), -1);
	if (try_create_image(
			loop_objs->mlx_ptr, loop_objs->window_area.width,
			loop_objs->window_area.height, &loop_objs->img
		) < 0)
		return (mlx_destroy_window(loop_objs->mlx_ptr, loop_objs->win_ptr),
			mlx_destroy_display(loop_objs->mlx_ptr), -1);
	loop_objs->zoom_state = (t_current_area){0.0, 0.0, 1.0, 1.0};
	return (0);
}

void	destroy_mlx_objs(t_mlx_loop_objs *loop_objs)
{
	mlx_destroy_image(loop_objs->mlx_ptr, loop_objs->img.img_ptr);
	mlx_destroy_window(loop_objs->mlx_ptr, loop_objs->win_ptr);
	mlx_destroy_display(loop_objs->mlx_ptr);
}
