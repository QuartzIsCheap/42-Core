
#include "libft.h"

size_t	ft_nputendl_fd(const char *str, int fd)
{
	size_t	count;

	count = 0;
	count += ft_nputstr_fd(str, fd);
	count += ft_nputchar_fd('\n', fd);
	return (count);
}
