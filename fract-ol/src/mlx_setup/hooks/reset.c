/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:43:26 by aronez            #+#    #+#             */
/*   Updated: 2022/11/19 16:43:26 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_setup.h"

#define KEY_R 114

int	reset_hook(int keycode, void *data)
{
	if (keycode == KEY_R)
		((t_mlx_loop_objs *)data)->zoom_state
			= (t_current_area){0.0, 0.0, 1.0, 1.0};
	return (0);
}
