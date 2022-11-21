/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:17 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 11:15:17 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_H
# define MLX_IMG_H

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}	t_img;

int	try_create_image(void *mlx_ptr, int width, int height, t_img *img);

#endif //MLX_IMG_H
