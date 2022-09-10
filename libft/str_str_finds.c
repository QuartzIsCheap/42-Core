
#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	size_t	str_len;
	size_t	substr_len;
	size_t	i;

	substr_len = ft_strlen(substr);
	if (substr_len == 0)
		return ((char *)str);
	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len - substr_len)
	{
		if (ft_strncmp(str + i, substr, substr_len) == 0)
				return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	substr_len;
	size_t	i;

	substr_len = ft_strlen(substr);
	if (substr_len == 0)
		return ((char *)str);
	i = 0;
	while (i < len - substr_len)
	{
		if (ft_strncmp(str + i, substr, substr_len) == 0)
				return ((char *)str + i);
		i++;
	}
	return (NULL);
}
