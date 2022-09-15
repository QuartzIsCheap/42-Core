
#include <unistd.h>

#include "libft.h"

void	ft_putstrn_fd(const char *str, size_t count, int fd)
{
	write(fd, str, ft_strnlen(str, count));
}
