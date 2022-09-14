
#include <unistd.h>

#include "libft.h"

size_t	ft_nputstr_fd(const char *str, int fd)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	write(fd, str, str_len);
	return (str_len);
}
