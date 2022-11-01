/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:28:11 by aronez            #+#    #+#             */
/*   Updated: 2022/10/26 10:28:11 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

static void	free_strs(char **strs)
{
	char	**strs_mem;

	strs_mem = strs;
	while (*strs != NULL)
	{
		free(*strs);
		strs++;
	}
	free(strs_mem);
}

static int	parse_int_array(char **strs, t_ft_lvec *stack)
{
	int	element;

	while (*strs != NULL)
	{
		if (ft_s_atoi(*strs, &element) < 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (ft_lvec_free(stack), -1);
		}
		if (ft_lvec_contains(stack, element))
		{
			ft_putstr_fd("Error\n", 2);
			return (ft_lvec_free(stack), -1);
		}
		if (ft_lvec_push_back(stack, element) < 0)
			return (-1);
		strs++;
	}
	return (0);
}

int	parse_args_into_stack(int argc, char *argv[], t_ft_lvec *stack)
{
	char	**strs;

	if (argc < 2)
		stack->length = 0;
	else if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (strs == NULL)
			return (-1);
		if (ft_lvec_with_capacity(stack, (ft_strlen(argv[1]) + 1) / 2) < 0)
			return (free_strs(strs), -1);
		if (parse_int_array(strs, stack) < 0)
			return (free_strs(strs), -1);
		free_strs(strs);
	}
	else
	{
		if (ft_lvec_with_capacity(stack, argc) < 0)
			return (-1);
		if (parse_int_array(argv + 1, stack) < 0)
			return (-1);
	}
	return (0);
}
