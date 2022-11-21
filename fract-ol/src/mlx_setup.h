/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:49:29 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 10:49:29 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_SETUP_H
# define MLX_SETUP_H

# include "mlx_img.h"
# include "zoom.h"

typedef struct s_mlx_loop_objs
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				img;
	t_current_area		zoom_state;
	t_window_area		window_area;
	void				(*img_writer)(const t_img *, t_current_area, void *);
	void				*set_parameters;
}	t_mlx_loop_objs;

int		init_mlx_objs(t_mlx_loop_objs *loop_objs);
void	setup_controller_hooks(t_mlx_loop_objs *loop_objs);
void	destroy_mlx_objs(t_mlx_loop_objs *loop_objs);

#endif //MLX_SETUP_H
