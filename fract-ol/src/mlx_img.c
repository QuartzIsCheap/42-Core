/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:45:36 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 11:45:36 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>

#include "mlx_img.h"

int	try_create_image(void *mlx_ptr, int width, int height, t_img *img)
{
	void	*img_ptr;

	img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (img_ptr == NULL)
		return (-1);
	img->img_ptr = img_ptr;
	img->width = width;
	img->height = height;
	return (0);
}
