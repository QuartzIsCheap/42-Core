/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stdint.h>

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*result;

	if (num == 0 || size == 0 || SIZE_MAX / size < num)
		return (NULL);
	result = malloc(num * size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, num * size);
	return (result);
}
