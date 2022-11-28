/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:42:00 by aronez            #+#    #+#             */
/*   Updated: 2022/11/27 13:42:00 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <libft.h>

#include "../commands.h"

static size_t	compute_commands_count(int argc, int here_doc_flag)
{
	size_t	program_name_count;
	size_t	token_count;
	size_t	file_name_count;

	program_name_count = 1;
	if (here_doc_flag)
	{
		token_count = 2;
		file_name_count = 1;
	}
	else
	{
		token_count = 0;
		file_name_count = 2;
	}
	return ((size_t)argc - program_name_count - token_count - file_name_count);
}

static void	prepend_to_empty_string_array(t_pipe_chain_commands *commands)
{
	size_t	i;

	i = -1;
	while (++i < commands->commands_count)
	{
		if (commands->command_array[i][0] == NULL)
		{
			free(commands->command_array[i]);
			commands->command_array[i] = ft_calloc(2, sizeof(char **));
			commands->command_array[i][0] = ft_strdup("");
		}
	}
}

t_pipe_chain_commands	parse_commands(int argc, char **argv)
{
	t_pipe_chain_commands	commands;
	size_t					i;
	int						here_doc_flag;

	here_doc_flag = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0)
		here_doc_flag = 1;
	commands.commands_count = compute_commands_count(argc, here_doc_flag);
	commands.command_array = ft_calloc(
			commands.commands_count, sizeof(char **)
			);
	i = -1;
	while (++i < commands.commands_count)
		commands.command_array[i] = ft_split(
				argv[1 + 1 + here_doc_flag + i], ' '
				);
	prepend_to_empty_string_array(&commands);
	return (commands);
}
