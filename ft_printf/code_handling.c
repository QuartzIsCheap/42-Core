
#include <stdarg.h>
#include <malloc.h>

#include "libft.h"

char	*handle_char(char code, va_list args)
{
	char	c;

	c = '%';
	if (code == 'c')
		c = va_arg(args, int);
	return (ft_strndup(&c, 1));
}

char	*handle_pointer(void *p)
{
	char	*hexa_ptr_int;
	char	*result;

	if (p == NULL)
		return (ft_strdup("(nil)"));
	hexa_ptr_int = ft_lltoa_base((long long)p, "0123456789abcdef");
	result = ft_strjoin("0x", hexa_ptr_int);
	free(hexa_ptr_int);
	return (result);
}
