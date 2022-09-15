
#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len + 1)
	{
		if (str[len - i] == ch)
			return ((char *)(str + (len - i)));
		i++;
	}
	return (NULL);
}
