
#include "libft.h"

int	ft_isalnum(int ch)
{
	return (ft_isalpha(ch) || ft_isdigit(ch));
}

int	ft_iscntrl(int ch)
{
	return ((0x00 <= ch && ch <= 0x1F) || ch == 0x7F);
}

int	ft_isspace(int ch)
{
	return (ch == ' ');
}

int	ft_isblank(int ch)
{
	return (ft_isspace(ch) || ch == '\t');
}

int	ft_ispunct(int ch)
{
	return (
			('!' <= ch && ch <= '/') ||
			(':' <= ch && ch <= '@') ||
			('[' <= ch && ch <= '`') ||
			('{' <= ch && ch <= '~')
			);
}
