
#include "libft.h"

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
