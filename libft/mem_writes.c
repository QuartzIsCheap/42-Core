
#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[len] = '\0';
		i++;
	}
}

void	*ft_memset(void *dest, int ch, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)dest)[i] = (unsigned char)ch;
		i++;
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (dest < src && src <= dest + count)
	{
		i = 0;
		while (i < count)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else if (src < dest && dest <= src + count)
	{
		i = 0;
		while (i < count)
		{
			((unsigned char *)dest)[count - 1 - i] =
					((const unsigned char *)src)[count - 1 - i];
			i++;
		}
	}
	else if (src != dest)
		ft_memcpy(dest, src, count);
	return (dest);
}
