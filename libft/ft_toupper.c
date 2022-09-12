
#include "libft.h"

int	ft_toupper(int ch)
{
	if (ft_islower(ch))
		return (ch + ('A' - 'a'));
	return (ch);
}
