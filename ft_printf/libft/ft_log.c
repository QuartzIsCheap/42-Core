
#include "../libft.h"

int ft_log(long long n, int base)
{
	int	log;

	log = 0;
	while (n / base != 0)
	{
		n /= base;
		log++;
	}
	return (log);
}
