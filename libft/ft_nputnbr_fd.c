
#include "libft.h"

size_t	ft_nputnbr_fd(int n, int fd)
{
	size_t	count;

	count = ft_nputllnbr_fd(n, fd);
	return (count);
}
