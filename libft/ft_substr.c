
#include <malloc.h>

#include "libft.h"

char	*ft_substr(const char *str, size_t start, size_t len)
{
	char	*result;
	size_t	i;

	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len && str[start + i] != '\0')
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
