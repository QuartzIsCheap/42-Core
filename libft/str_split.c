
#include <malloc.h>

#include "libft.h"

static int	counts_strs(const char *substr, size_t len, void *data)
{
	(void)substr;
	(void)len;
	(*(size_t *)data)++;
	return (0);
}

static int	make_strs(const char *substr, size_t len, void *data)
{
	char	**strs;

	strs = (char **)data;
	while (*strs != NULL)
		strs++;
	*strs = ft_strndup(substr, len);
	if (*strs == NULL)
		return (-1);
	return (0);
}

static int	invoke_on_substrs(
		const char *str,
		char c,
		int (*f)(const char *, size_t, void *),
		void *data
		)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = -1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (j - i - 1 > 0 && f(str + (j + 1), j - i - 1, data) < 0)
				return (-1);
			j = i;
		}
		i++;
	}
	if (j - i > 1)
		f(str + (j + 1), j - i - 1, data);
	return (0);
}

char	**ft_split(const char *str, char c)
{
	size_t	strs_count;
	char	**strs;
	size_t	i;

	strs_count = 0;
	if (invoke_on_substrs(str, c, &counts_strs, &strs_count) < 0)
		return (NULL);
	strs = ft_calloc(strs_count + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	if (invoke_on_substrs(str, c, &make_strs, strs) < 0)
	{
		i = 0;
		while (strs[i] != NULL)
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		return (NULL);
	}
	return (strs);
}
