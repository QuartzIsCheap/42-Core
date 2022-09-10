
#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	size_t	dest_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	return (dest);
}

char		*ft_strncat(char *dest, const char *src, size_t count)
{
	size_t	dest_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (i < count && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len != size)
		dest_len++;
	if (dest_len == size)
		return (size);
	i = 0;
	while (dest_len + i < size - 1 && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	while (src[i] != '\0')
		i++;
	return (dest_len + i);
}
