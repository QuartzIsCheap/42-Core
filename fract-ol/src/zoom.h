/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:55:04 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 13:55:04 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOOM_H
# define ZOOM_H

typedef struct s_current_area
{
	double	x;
	double	y;
	double	width;
	double	height;
}	t_current_area;

typedef struct s_window_area
{
	int	width;
	int	height;
}	t_window_area;

#endif //ZOOM_H
