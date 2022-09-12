
#include "libft.h"

int	ft_iscntrl(int ch)
{
	return ((0x00 <= ch && ch <= 0x1F) || ch == 0x7F);
}
