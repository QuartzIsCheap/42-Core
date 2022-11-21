/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:51:34 by aronez            #+#    #+#             */
/*   Updated: 2022/11/19 13:51:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_setup.h"
#include "../../zoom.h"

#define MOUSE_SCROLL_UP 4
#define MOUSE_SCROLL_DOWN 5

int	zoom_hook(int button, int x, int y, void *data)
{
	t_mlx_loop_objs	*objs;
	double			scroll_amount;
	double			zoom_ratio;

	objs = (t_mlx_loop_objs *)data;
	if (button == MOUSE_SCROLL_UP)
		scroll_amount = 1.0;
	else if (button == MOUSE_SCROLL_DOWN)
		scroll_amount = -1.0;
	else
		scroll_amount = 0.0;
	zoom_ratio = objs->zoom_state.width;
	objs->zoom_state.x += scroll_amount
		* ((double)x / objs->window_area.width) * 0.5 * zoom_ratio;
	objs->zoom_state.y += scroll_amount
		* ((double)y / objs->window_area.height) * 0.5 * zoom_ratio;
	objs->zoom_state.width -= scroll_amount * 0.5 * zoom_ratio;
	objs->zoom_state.height -= scroll_amount * 0.5 * zoom_ratio;
	return (0);
}

#define ARROW_LEFT 65361
#define ARROW_UP 65362
#define ARROW_RIGHT 65363
#define ARROW_DOWN 65364

int	pan_hook(int keycode, void *data)
{
	t_current_area	*zoom_state;

	zoom_state = &((t_mlx_loop_objs *)data)->zoom_state;
	if (keycode == ARROW_LEFT)
		zoom_state->x -= zoom_state->width / 16.0;
	else if (keycode == ARROW_RIGHT)
		zoom_state->x += zoom_state->width / 16.0;
	else if (keycode == ARROW_UP)
		zoom_state->y -= zoom_state->height / 16.0;
	else if (keycode == ARROW_DOWN)
		zoom_state->y += zoom_state->height / 16.0;
	return (0);
}
