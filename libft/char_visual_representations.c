
#include "libft.h"

int	ft_isgraph(int ch)
{
	return ('!' <= ch && ch <= '~');
}

int	ft_isprint(int ch)
{
	return (ft_isgraph(ch) || ch == ' ');
}
