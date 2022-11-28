/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:39:01 by aronez            #+#    #+#             */
/*   Updated: 2022/11/27 13:39:01 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <libft.h>

#include "../commands.h"

void	free_commands(t_pipe_chain_commands commands)
{
	size_t	i;

	i = 0;
	while (i < commands.commands_count)
	{
		ft_free_strs(commands.command_array[i]);
		i++;
	}
	free(commands.command_array);
}
