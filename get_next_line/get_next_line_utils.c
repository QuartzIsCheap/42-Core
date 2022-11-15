/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:40:45 by aronez            #+#    #+#             */
/*   Updated: 2022/11/03 16:40:45 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>

#include "get_next_line.h"

static char	*ft_strncpy(char *dest, const char *src, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < count)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	*ft_strnchr(const char *str, int ch, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

int	extend_line(
		char **line,
		size_t current_line_len,
		size_t additional_size,
		const char *buffer
		)
{
	char	*new_line;
	size_t	i;

	new_line = malloc(sizeof(char) * (current_line_len + additional_size + 1));
	if (new_line != NULL)
	{
		i = 0;
		while (i < current_line_len)
		{
			new_line[i] = (*line)[i];
			i++;
		}
	}
	free(*line);
	*line = new_line;
	if (*line == NULL)
		return (-1);
	ft_strncpy(*line + current_line_len, buffer, additional_size);
	(*line)[current_line_len + additional_size] = '\0';
	return (0);
}

int	init_sub_buffer(t_sub_buffer *sub_buffer)
{
	if (sub_buffer->buffer == NULL)
	{
		sub_buffer->buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (sub_buffer->buffer == NULL)
			return (-1);
	}
	return (0);
}

int	extract_from_buffer(
		t_sub_buffer *sub_buffer,
		char **line,
		size_t *current_line_len)
{
	const char	*line_break;
	size_t		additional_size;
	int			return_value;
	const char	*buffer;

	if (init_sub_buffer(sub_buffer) < 0)
		return (1);
	buffer = sub_buffer->buffer + sub_buffer->start;
	line_break = ft_strnchr(
			buffer, '\n', sub_buffer->buffer_size - sub_buffer->start
			);
	return_value = 1;
	if (line_break == NULL)
	{
		line_break = sub_buffer->buffer + sub_buffer->buffer_size;
		return_value = 0;
	}
	else
		line_break++;
	additional_size = (line_break - sub_buffer->buffer) - sub_buffer->start;
	if (extend_line(line, *current_line_len, additional_size, buffer) < 0)
		return (free(sub_buffer->buffer), 1);
	*current_line_len += additional_size;
	sub_buffer->start = line_break - sub_buffer->buffer;
	return (return_value);
}
