
#include <malloc.h>

#include "libft.h"

size_t	ft_nputllnbr_fd(long long n, int fd)
{
	char	*n_str;
	size_t	count;

	n_str = ft_lltoa(n);
	count = ft_nputstr_fd(n_str, fd);
	free(n_str);
	return (count);
}
