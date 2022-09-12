
#include "libft.h"

static int	extract_sign(const char **str)
{
	int	multiplier;

	while (ft_isspace(**str))
		(*str)++;
	multiplier = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			multiplier = -1;
		(*str)++;
	}
	return (multiplier);
}

long	ft_atol(const char *str)
{
	long	multiplier;
	long	result;
	size_t	digit_count;
	size_t	i;

	multiplier = extract_sign(&str);
	digit_count = 0;
	while (ft_isdigit(str[digit_count]))
		digit_count++;
	result = 0;
	i = 0;
	while (i < digit_count)
	{
		result += multiplier * (str[digit_count - 1 - i] - '0');
		multiplier *= 10;
		i++;
	}
	return (result);
}
