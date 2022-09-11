
#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_strnchr(const char *str, int ch, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[len - 1 - i] == ch)
			return ((char *)(str + (len - 1 - i)));
		i++;
	}
	return (NULL);
}
