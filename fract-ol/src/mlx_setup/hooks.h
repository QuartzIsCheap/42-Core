/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:13:44 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 13:13:44 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

int	escape_close_hook(int keycode, void *data);
int	close_hook(void *mlx_ptr);
int	zoom_hook(int button, int x, int y, void *data);
int	pan_hook(int keycode, void *data);
int	reset_hook(int keycode, void *data);

#endif //HOOKS_H
