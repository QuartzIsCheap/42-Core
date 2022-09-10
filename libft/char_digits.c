
#include "libft.h"

int	ft_isdigit(int ch)
{
	return ('0' <= ch && ch <= '9');
}

int	ft_isxdigit(int ch)
{
	return (
			ft_isdigit(ch) ||
			('a' <= ch && ch <= 'f') ||
			('A' <= ch && ch <= 'F')
			);
}
