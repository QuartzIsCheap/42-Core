
#include "libft.h"

int	ft_isupper(int ch)
{
	return ('A' <= ch && ch <= 'Z');
}

int	ft_islower(int ch)
{
	return ('a' <= ch && ch <= 'z');
}

int	ft_isalpha(int ch)
{
	return (ft_islower(ch) || ft_isupper(ch));
}
