
#include <limits.h>
#include <malloc.h>
#include <stdarg.h>
#include <stddef.h>

#include "libft.h"

char	*translate_printf_format_string(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*formatted_str;
	int		result;

	va_start(args, format);
	formatted_str = translate_printf_format_string(format, args);
	va_end(args);
	if (formatted_str == NULL)
		return (0);
	ft_putstr_fd(formatted_str, 1);
	result = (int)ft_smin(ft_strlen(formatted_str), INT_MAX);
	return (free(formatted_str), result);
}
