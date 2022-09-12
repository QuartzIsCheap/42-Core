
#include "libft.h"

int	ft_isprint(int ch)
{
	return (ft_isgraph(ch) || ch == ' ');
}
