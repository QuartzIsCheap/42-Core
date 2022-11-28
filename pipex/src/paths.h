/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:13:30 by aronez            #+#    #+#             */
/*   Updated: 2022/11/26 16:13:30 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

/**
 * Finds the PATH variable in the given list of environment variables, and
 * splits it around the ':' character. The resulting string are put in *paths,
 * which can be freed with ft_free_strs(char **). It is considered an error if
 * there is PATH variable defined but it has no entry ("PATH=").
 * @brief Finds the PATH variable and returns its values.
 * @param envp A list of environments variables as given to the main function.
 * @param paths The array of null-terminated strings where the paths will be
 * stored.
 * @return 0 in case of success, -1 otherwise, in which case no memory needs to
 * be freed.
 */
int		extract_paths(char *envp[], char ***paths);

/**
 * Allocates a new null-terminated string containing the too paths with an extra
 * '/' between them. File systems ignore multiple slashes when resolving paths,
 * so this is not an issue.
 * @brief Combines the two paths, adding a '/' between them.
 * @param path_a The starting path.
 * @param path_b The path to put after the '/'.
 * @return An newly allocated string as described above.
 */
char	*join_paths(char *path_a,char *path_b);

#endif //PATH_H
