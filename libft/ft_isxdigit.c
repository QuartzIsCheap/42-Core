
#include "libft.h"

int	ft_isxdigit(int ch)
{
	return (
			ft_isdigit(ch) ||
			('a' <= ch && ch <= 'f') ||
			('A' <= ch && ch <= 'F')
			);
}
