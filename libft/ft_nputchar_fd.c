
#include <unistd.h>

#include "libft.h"

size_t	ft_nputchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
