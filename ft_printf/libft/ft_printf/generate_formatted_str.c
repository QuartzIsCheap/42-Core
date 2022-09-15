
#include <malloc.h>

#include "../libft.h"

char	*handle_printf_code(char code, va_list args);

static size_t	count_strs(const char *format_str)
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

static void	free_strs(char **strs, size_t strs_count)
{
	size_t	i;

	i = 0;
	while (i < strs_count)
	{
		free(strs[i]);
		i++;
	}
}

static int	parse_strs(const char *format, va_list args, char **strs, size_t strs_count)
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
		strs[strs_i + 1] = handle_printf_code(*(cc + 1), args);
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

static char	**make_strs(const char *format, size_t strs_count, va_list args)
{
	char	**strs;

	strs = ft_calloc(strs_count, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	if (parse_strs(format, args, strs, strs_count) < 0)
		return (free(strs), NULL);
	return (strs);
}

char	*parse_formatted_str(const char *format, va_list args)
{
	size_t	strs_count;
	char	**strs;
	char	*formatted_str;

	strs_count = count_strs(format);
	strs = make_strs(format, strs_count, args);
	if (strs == NULL)
		return (NULL);
	formatted_str = ft_strsnjoin((const char **)strs, strs_count);
	free_strs(strs, strs_count);
	free(strs);
	return (formatted_str);
}
