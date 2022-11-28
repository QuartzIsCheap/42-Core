/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:12:25 by aronez            #+#    #+#             */
/*   Updated: 2022/11/20 11:12:25 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "commands.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe_chain_commands	commands;

	if (argc - 1 < 4 || (ft_strcmp(argv[1], "here_doc") == 0 && argc - 1 < 5))
		return (EXIT_SUCCESS);
	commands = parse_commands(argc, argv);
	if (try_resolve_commands(&commands, argv[0], envp) < 0)
		return (free_commands(commands), EXIT_FAILURE);
	return (free_commands(commands), EXIT_SUCCESS);
}
