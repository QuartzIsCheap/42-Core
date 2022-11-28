/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:27:40 by aronez            #+#    #+#             */
/*   Updated: 2022/11/28 10:27:40 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <libft.h>

int	extract_paths(char *envp[], char ***paths)
{
	while (*envp != NULL && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (*envp == NULL)
		return (-1);
	*paths = ft_split(*envp + 5, ':');
	if (*paths == NULL)
		return (-1);
	if (**paths == NULL)
		return (free(*paths), -1);
	return (0);
}
