
#include "libft.h"

size_t	ft_strnlen(const char *str, size_t count)
{
	size_t	len;

	len = 0;
	while (len < count && str[len] != '\0')
		len++;
	return (len);
}
