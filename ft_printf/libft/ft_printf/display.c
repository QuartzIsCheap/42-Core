/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../libft.h"

void	display_string(const char *str)
{
	size_t	prev_i;
	size_t	i;

	prev_i = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != -1)
			i++;
		if (i - prev_i > 0)
			ft_putstrn_fd(str + prev_i, i - prev_i, 1);
		if (str[i] == -1)
		{
			ft_putchar_fd(0, 1);
			i++;
			prev_i = i;
		}
	}
}
