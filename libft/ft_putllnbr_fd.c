
#include <malloc.h>

#include "libft.h"

void	ft_putllnbr_fd(long long n, int fd)
{
	char	*n_str;

	n_str = ft_lltoa(n);
	ft_putstr_fd(n_str, fd);
	free(n_str);
}
