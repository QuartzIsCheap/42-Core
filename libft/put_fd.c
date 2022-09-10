
#include <malloc.h>
#include <unistd.h>

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *c, int fd)
{
	write(fd, c, ft_strlen(c));
}

void	ft_putendl_fd(const char *c, int fd)
{
	ft_putstr_fd(c, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putllnbr_fd(long long n, int fd)
{
	char	*n_str;

	n_str = ft_lltoa(n);
	ft_putstr_fd(n_str, fd);
	free(n_str);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putllnbr_fd(n, fd);
}
