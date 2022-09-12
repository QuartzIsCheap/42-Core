
#include "libft.h"

int	ft_isblank(int ch)
{
	return (ft_isspace(ch) || ch == '\t');
}
