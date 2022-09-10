
#include "libft.h"

int	ft_isascii(int ch)
{
	return (0x00 <= ch && ch < 0x80);
}