
#include <limits.h>

#include "../libft.h"

long long	ft_llabs(long long n)
{
	if (n == LLONG_MIN)
		return (LLONG_MAX);
	if (n < 0)
		return (-n);
	return (n);
}
