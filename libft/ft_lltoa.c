
#include <malloc.h>

#include "libft.h"

static int	ft_log10(long long n)
{
	int	log;

	log = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		log++;
	}
	return (log);
}

char	*ft_lltoa(long long n)
{
	size_t	digit_count;
	char	*result;

	digit_count = ft_log10(n) + 1;
	if (n < 0)
		digit_count++;
	result = malloc(sizeof(char) * (digit_count + 1));
	if (result == NULL)
		return (NULL);
	result[digit_count] = '\0';
	if (n < 0)
		result[0] = '-';
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[digit_count - 1] = (char)(n % 10);
		digit_count--;
		n /= 10;
	}
	return (result);
}
