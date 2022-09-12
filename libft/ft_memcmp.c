
#include "libft.h"

int	ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	size_t	i;
	int		dif;

	i = 0;
	while (i < count)
	{
		dif = ((const unsigned char *)lhs)[i] - ((const unsigned char *)rhs)[i];
		if (dif != 0)
			return (dif);
		i++;
	}
	return (0);
}
