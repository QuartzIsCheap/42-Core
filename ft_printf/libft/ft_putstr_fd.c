
#include <unistd.h>

#include "../libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
