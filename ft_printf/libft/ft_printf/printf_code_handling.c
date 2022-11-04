/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_code_handling.c                             :+:      :+:    :+:   */
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
	char	c;

	c = '%';
	if (code == 'c')
		c = va_arg(args, int);
	return (ft_strndup(&c, 1));
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
	const char	*base;

	if (code == '%' || code == 'c')
		return (handle_char(code, args));
	else if (code == 's')
		return (ft_strdup(va_arg(args, const char *)));
	else if (code == 'p')
		return (handle_pointer(va_arg(args, void *)));
	else if (code == 'd' || code == 'i')
		return (ft_lltoa_base(va_arg(args, int), "0123456789"));
	else
	{
		if (code == 'u')
			base = "0123456789";
		if (code == 'x')
			base = "0123456789abcdef";
		if (code == 'X')
			base = "0123456789ABCDEF";
		return (ft_lltoa_base(va_arg(args, unsigned int), base));
	}
}
