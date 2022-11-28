/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:28:34 by aronez            #+#    #+#             */
/*   Updated: 2022/11/28 10:28:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <libft.h>

char	*join_paths(char *path_a, char *path_b)
{
	const size_t	path_a_length = ft_strlen(path_a);
	const size_t	path_b_length = ft_strlen(path_b);
	char			*result;

	result = malloc((path_a_length + 1 + path_b_length + 1) * sizeof(char));
	ft_strcpy(result, path_a);
	result[path_a_length] = '/';
	ft_strcpy(result + (path_a_length + 1), path_b);
	return (result);
}
