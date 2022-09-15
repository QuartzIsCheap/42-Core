
#include <limits.h>
#include <malloc.h>
#include <stdarg.h>
#include <stddef.h>

#include "libft.h"

char	*handle_char(char code, va_list args);
char	*handle_pointer(void *p);

char	*handle_code(char code, va_list args)
{
	if (code == '%' || code == 'c')
		return (handle_char(code, args));
	else if (code == 's')
		return (ft_strdup(va_arg(args, const char *)));
	else if (code == 'p')
		return (handle_pointer(va_arg(args, void *)));
	else if (code == 'd' || code == 'i')
		return (ft_lltoa_base(va_arg(args, int), "0123456789"));
	else if (code == 'u')
		return (ft_lltoa_base(va_arg(args, unsigned int), "0123456789"));
	else if (code == 'x')
		return (ft_lltoa_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (code == 'X')
		return (ft_lltoa_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

size_t	count_strs(const char *format_str)
{
	size_t	count;

	count = 0;
	format_str = ft_strchr(format_str, '%');
	while (format_str != NULL)
	{
		count++;
		format_str = ft_strchr(format_str + 2, '%');
	}
	return (count + (count + 1));
}

void	free_strs(char **strs, size_t strs_count)
{
	size_t	i;

	i = 0;
	while (i < strs_count)
	{
		free(strs[i]);
		i++;
	}
}

int	parse_strs(const char *format, va_list args, char **strs, size_t strs_count)
{
	size_t		strs_i;
	const char	*prev_cc;
	const char	*cc;

	strs_i = 0;
	prev_cc = format;
	cc = ft_strchr(prev_cc, '%');
	while (cc != NULL)
	{
		strs[strs_i] = ft_strndup(prev_cc, (size_t)(cc - prev_cc));
		strs[strs_i + 1] = handle_code(*(cc + 1), args);
		if (strs[strs_i] == NULL || strs[strs_i + 1] == NULL)
			return (free_strs(strs, strs_count), -1);
		strs_i += 2;
		prev_cc = cc + 2;
		cc = ft_strchr(prev_cc, '%');
	}
	strs[strs_i] = ft_strdup(prev_cc);
	if (strs[strs_i] == NULL)
		return (free_strs(strs, strs_count), -1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	strs_count;
	char	**strs;
	va_list	args;
	char	*formatted_str;
	int		result;

	strs_count = count_strs(format);
	strs = ft_calloc(strs_count, sizeof(char *));
	if (strs == NULL)
		return (0);
	va_start(args, format);
	if (parse_strs(format, args, strs, strs_count) < 0)
		return (free(strs), 0);
	va_end(args);
	formatted_str = ft_strsnjoin((const char **)strs, strs_count);
	free_strs(strs, strs_count);
	free(strs);
	if (formatted_str == NULL)
		return (0);
	ft_putstr_fd(formatted_str, 1);
	result = (int)ft_smin(ft_strlen(formatted_str), INT_MAX);
	free(formatted_str);
	return (result);
}
