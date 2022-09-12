
#include "libft.h"

int	ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
	size_t	i;

	i = 0;
	while (i + 1 < count && lhs[i] != '\0' && lhs[i] == rhs[i])
		i++;
	return (lhs[i] - rhs[i]);
}
