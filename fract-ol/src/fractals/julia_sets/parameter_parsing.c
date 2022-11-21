/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:53:36 by aronez            #+#    #+#             */
/*   Updated: 2022/11/17 13:53:36 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/types.h>

#include "../../fractals.h"

static double	read_sign(const char **parameter)
{
	double	multiplier;

	multiplier = 1.0;
	if ((*parameter)[0] == '+' || (*parameter)[0] == '-')
	{
		if ((*parameter)[0] == '-')
			multiplier = -1.0;
		(*parameter)++;
	}
	return (multiplier);
}

static double	parse_decimals(const char *decimals)
{
	double	decimal_part;
	size_t	i;
	double	log;

	decimal_part = 0.0;
	i = 0;
	log = 0.1;
	while ('0' <= decimals[i] && decimals[i] <= '9')
	{
		decimal_part += log * (decimals[i] - '0');
		log /= 10.0;
		i++;
	}
	return (decimal_part);
}

static int	try_parse_argument(const char *parameter, double *c_component)
{
	double	multiplier;

	multiplier = read_sign(&parameter);
	if ('0' <= parameter[0] && parameter[0] <= '1')
		*c_component = multiplier * (double)(parameter[0] - '0');
	else
		return (-1);
	if (parameter[1] == '\0')
		return (0);
	else if (parameter[1] != '.')
		return (-1);
	*c_component = multiplier * parse_decimals(parameter + 2);
	if (-1.0 <= *c_component && *c_component <= 1.0)
		return (0);
	else
		return (-1);
}

int	try_parse_julia_parameters(
		char *parameters_str[],
		t_julia_parameters *julia_parameters
		)
{
	if (try_parse_argument(parameters_str[0], &julia_parameters->cx) < 0)
		return (-1);
	if (try_parse_argument(parameters_str[1], &julia_parameters->cy) < 0)
		return (-1);
	return (0);
}
