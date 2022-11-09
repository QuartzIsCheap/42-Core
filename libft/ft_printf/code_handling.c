/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <malloc.h>

#include "../libft.h"

static char	*handle_char(char code, va_list args)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	str[0] = '%';
	if (code == 'c')
	{
		str[0] = va_arg(args, int);
		if (str[0] == 0)
			str[0] = -1;
	}
	str[1] = '\0';
	return (str);
}

static char	*handle_pointer(void *p)
{
	char	*hexa_ptr_addr;
	char	*result;

	if (p == NULL)
		return (ft_strdup("(nil)"));
	hexa_ptr_addr = ft_ulltoa_base((uintptr_t)p, "0123456789abcdef");
	result = ft_strjoin("0x", hexa_ptr_addr);
	free(hexa_ptr_addr);
	return (result);
}

char	*handle_printf_code(char code, va_list args)
{
	const char	*tmp;

	if (code == '%' || code == 'c')
		return (handle_char(code, args));
	else if (code == 's')
	{
		tmp = va_arg(args, const char *);
		if (tmp == NULL)
			return (ft_strdup("(null)"));
		return (ft_strdup(tmp));
	}
	else if (code == 'p')
		return (handle_pointer(va_arg(args, void *)));
	else if (code == 'd' || code == 'i')
		return (ft_lltoa_base(va_arg(args, int), "0123456789"));
	else
	{
		if (code == 'u')
			tmp = "0123456789";
		if (code == 'x')
			tmp = "0123456789abcdef";
		if (code == 'X')
			tmp = "0123456789ABCDEF";
		return (ft_lltoa_base(va_arg(args, unsigned int), tmp));
	}
}
