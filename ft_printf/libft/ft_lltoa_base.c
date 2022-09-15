
#include <malloc.h>

#include "../libft.h"

char	*ft_lltoa_base(long long n, const char *base)
{
	char	*unsigned_str;
	char	*signed_str;

	if (n >= 0)
		return (ft_ulltoa_base(n, base));
	unsigned_str = ft_ulltoa_base(-n, base);
	if (unsigned_str == NULL)
		return (NULL);
	signed_str = ft_strjoin("-", unsigned_str);
	free(unsigned_str);
	return (signed_str);
}
