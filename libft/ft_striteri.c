
#include "libft.h"

void	ft_striteri(char *str, void (*f)(size_t, char *))
{
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len)
	{
		f(i, str + i);
		i++;
	}
}
