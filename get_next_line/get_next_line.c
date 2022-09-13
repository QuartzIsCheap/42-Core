
#include <malloc.h>
#include <stddef.h>
#include <unistd.h>

#include "get_next_line.h"

char	*realloc_line(
		char *line,
		size_t current_length,
		size_t additional_size
);
char	*ft_strncpy(char *dest, const char *src, size_t count);
char	*ft_strnchr(const char *str, int ch, size_t count);
int	extract_from_buffer(
		t_sub_buffer *sub_buffer,
		char **line,
		size_t *current_line_len
		);

char	*get_next_line(int fd)
{
	static t_sub_buffer	sub_buffer = {.start = 0, .buffer_size = 0};
	char				*line;
	size_t				current_line_len;

	line = NULL;
	current_line_len = 0;
	if (extract_from_buffer(&sub_buffer, &line, &current_line_len))
		return (line);
	sub_buffer.buffer_size = read(fd, sub_buffer.buffer, BUFFER_SIZE);
	if (sub_buffer.buffer_size <= 0 && current_line_len == 0)
	{
		sub_buffer = (t_sub_buffer){.start = 0, .buffer_size = 0};
		return (free(line), NULL);
	}
	sub_buffer.start = 0;
	while (sub_buffer.buffer_size > 0)
	{
		if (extract_from_buffer(&sub_buffer, &line, &current_line_len))
			return (line);
		sub_buffer.buffer_size = read(fd, sub_buffer.buffer, BUFFER_SIZE);
		sub_buffer.start = 0;
	}
	sub_buffer = (t_sub_buffer){.start = 0, .buffer_size = 0};
	return (line);
}
