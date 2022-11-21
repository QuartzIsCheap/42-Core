/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:14:32 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 13:14:32 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "../../mlx_setup.h"

#define ESCAPE_KEYSYM 65307

int	close_hook(void *mlx_ptr)
{
	mlx_loop_end(mlx_ptr);
	return (0);
}

int	escape_close_hook(int keycode, void *data)
{
	if (keycode == ESCAPE_KEYSYM)
		mlx_loop_end(((t_mlx_loop_objs *)data)->mlx_ptr);
	return (0);
}
