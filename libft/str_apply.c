
#include <malloc.h>

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(size_t, char))
{
	size_t	str_len;
	char	*result;
	size_t	i;

	str_len = ft_strlen(str);
	result = malloc(sizeof(char) * (str_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[str_len] = '\0';
	return (result);
}

void	ft_striteri(char *str, void (*f)(size_t, char *))
{
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		f(i, str + i);
		i++;
	}
}
