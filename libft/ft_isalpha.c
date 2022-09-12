
#include "libft.h"

int	ft_isalpha(int ch)
{
	return (ft_islower(ch) || ft_isupper(ch));
}
