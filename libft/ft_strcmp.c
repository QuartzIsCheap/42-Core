
#include "libft.h"

int	ft_strcmp(const char *lhs, const char *rhs)
{
	size_t	i;

	i = 0;
	while (lhs[i] != '\0' && lhs[i] == rhs[i])
		i++;
	return (lhs[i] - rhs[i]);
}
