
#include "libft.h"

int	ft_toupper(int ch)
{
	if (ft_islower(ch))
		return (ch + ('A' - 'a'));
	return (ch);
}

int	ft_tolower(int ch)
{
	if (ft_isupper(ch))
		return (ch + ('a' - 'A'));
	return (ch);
}
