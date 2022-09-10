
#include <limits.h>
#include "libft.h"

int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (INT_MAX);
	if (n < 0)
		return (-n);
	return (n);
}

long	ft_labs(long n)
{
	if (n == LONG_MIN)
		return (LONG_MAX);
	if (n < 0)
		return (-n);
	return (n);
}

long long	ft_llabs(long long n)
{
	if (n == LLONG_MIN)
		return (LLONG_MAX);
	if (n < 0)
		return (-n);
	return (n);
}
