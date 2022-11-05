/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:40:45 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 16:40:45 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_sub_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	start;
	ssize_t	buffer_size;
}	t_sub_buffer;

/**
 * Given a file descriptor opened and only ever read from within this function,
 * returns the next segment of characters separated by a line break. The line
 * break is included, and the string is null-terminated. The last line of the
 * file may not have a line break at its end. Once the whole file has been read,
 * the function will return NULL. It must not be called again. It can then be
 * used to read the contents of another file, or of the same file if it has been
 * re-opened.
 * @brief Reads a file line by line.
 * @param fd A file descriptor to the file to read from.
 * @return Null-terminated strings, including a trailing return line if there is
 * one to include, or NULL if EOF is reached.
 */
char	*get_next_line(int fd);

#endif //GET_NEXT_LINE_H
