/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:37:48 by aronez            #+#    #+#             */
/*   Updated: 2022/11/27 13:37:48 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <stddef.h>

/**
 * @brief A command is a string containing its invocation path followed by a
 * bunch of strings containing the parameters to the invocation. The pointer
 * array itself is NULL-terminated.
 */
typedef char	**t_command;

/**
 * @brief An array of commands as needed by the pipe chain system. It is not
 * NULL-terminated as its length is known.
 */
typedef struct s_pipe_chain_commands
{
	t_command	*command_array;
	size_t		commands_count;
}	t_pipe_chain_commands;

/**
 * Using ft_free_strs, frees all the commands one by one, then frees the array
 * of commands.
 * @brief Frees all memory within the given instance.
 * @param commands The instance in which memory must be freed.
 */
void					free_commands(t_pipe_chain_commands commands);

/**
 * Extracts from the program arguments the different commands that need to be
 * piped. To that end, it allocated an array of t_command of a size dependent on
 * whether the ```here_doc``` token is present or not. The array is then
 * populated with the command strings in argv split around the ' ' character. If
 * parsing a command would yield an empty array of strings, an empty string is
 * prepended.
 * @brief Parses textually the commands into a nice commands structure.
 * @param argc The program's argument count.
 * @param argv The program arguments.
 * @return The structure in which the commands are parsed.
 */
t_pipe_chain_commands	parse_commands(int argc, char **argv);

/**
 * Extracts the PATH variable from the set of environment variables given to the
 * program. Then, for all commands in the commands array, tries to find a prefix
 * from the paths such that the absolute path obtained is an executable file.
 * Also checks by adding no prefix, which makes absolute paths work. The command
 * name is then replaced by this absolute path in the array of commands. If
 * there is no PATH variable properly defined, or if a command is not found,
 * displays the error and returns -1.
 * @param commands The array of commands to resolve and replace.
 * @param self_name The name of the program itself, as given to the name, for
 * error writing.
 * @param envp The set of environment variables given to the program.
 * @return 0 in case of success, -1 otherwise.
 */
int						try_resolve_commands(
							t_pipe_chain_commands *commands,
							const char *self_name,
							char **envp
							);

#endif //COMMANDS_H
