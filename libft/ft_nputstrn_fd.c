
#include <unistd.h>

#include "libft.h"

size_t	ft_nputstrn_fd(const char *str, size_t count, int fd)
{
	size_t	str_len;

	str_len = ft_strnlen(str, count);
	write(fd, str, str_len);
	return (str_len);
}
