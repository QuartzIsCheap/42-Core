
#include <malloc.h>

#include "../libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*result;

	result = malloc(num * size);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, num * size);
	return (result);
}
