
#include <malloc.h>
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < count)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*copy;
	size_t	i;

	src_len = ft_strlen(src);
	copy = malloc(sizeof(char) * (src_len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < src_len + 1)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}

char	*ft_strndup(const char *src, size_t count)
{
	size_t	src_len;
	char	*copy;
	size_t	i;

	src_len = 0;
	while (src_len < count && src[src_len] != '\0')
		src_len++;
	copy = malloc(sizeof(char) * (src_len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
