/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:07:36 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 13:07:36 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/X.h>

#include "../mlx_setup.h"

#include "hooks.h"

static int	loop_body(void *data)
{
	t_mlx_loop_objs	*loop_objs;

	loop_objs = (t_mlx_loop_objs *)data;
	loop_objs->img_writer(&loop_objs->img, loop_objs->zoom_state,
		loop_objs->set_parameters);
	mlx_put_image_to_window(loop_objs->mlx_ptr, loop_objs->win_ptr,
		loop_objs->img.img_ptr, 0, 0);
	return (0);
}

static int	key_hooks(int keycode, void *data)
{
	pan_hook(keycode, data);
	escape_close_hook(keycode, data);
	reset_hook(keycode, data);
	return (0);
}

void	setup_controller_hooks(t_mlx_loop_objs *loop_objs)
{
	mlx_hook(loop_objs->win_ptr, DestroyNotify, ButtonReleaseMask,
		&close_hook, loop_objs->mlx_ptr);
	mlx_key_hook(loop_objs->win_ptr, &key_hooks, loop_objs);
	mlx_loop_hook(loop_objs->mlx_ptr, &loop_body, loop_objs);
	mlx_mouse_hook(loop_objs->win_ptr, &zoom_hook, loop_objs);
}
