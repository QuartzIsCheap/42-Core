/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:00:15 by aronez            #+#    #+#             */
/*   Updated: 2022/11/27 18:00:15 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <unistd.h>
#include <libft.h>

#include "../commands.h"
#include "../paths.h"

static int	try_resolve_as_path_combination(char **command, char **paths)
{
	size_t			i;
	char			*resolve_candidate;

	i = -1;
	while (paths[++i] != NULL)
	{
		resolve_candidate = join_paths(paths[i], *command);
		if (access(resolve_candidate, X_OK) == 0)
		{
			free(*command);
			*command = resolve_candidate;
			return (0);
		}
		else
			free(resolve_candidate);
	}
	return (-1);
}

static int	try_resolve_command_with_path(char **command, char **paths)
{
	if (ft_strlen(*command) == 0)
		return (-1);
	if (access(*command, X_OK) == 0)
		return (0);
	if (try_resolve_as_path_combination(command, paths) == 0)
		return (0);
	return (-1);
}

static int	try_resolve_commands_with_path(
		t_pipe_chain_commands *commands,
		char **paths,
		const char *self_name
		)
{
	size_t	i;

	i = -1;
	while (++i < commands->commands_count)
	{
		if (try_resolve_command_with_path(
				&commands->command_array[i][0], paths
		) < 0)
		{
			ft_fdprintf(2, "%s: %s: Command not found\n", self_name,
					commands->command_array[i][0]);
			return (-1);
		}
	}
	return (0);
}

int	try_resolve_commands(
		t_pipe_chain_commands *commands,
		const char *self_name,
		char **envp
		)
{
	char	**paths;

	if (extract_paths(envp, &paths) < 0)
	{
		ft_fdprintf(2, "%s: No valid PATH variable\n", self_name);
		return (-1);
	}
	if (try_resolve_commands_with_path(commands, paths, self_name) < 0)
		return (ft_free_strs(paths), -1);
	return (ft_free_strs(paths), 0);
}
