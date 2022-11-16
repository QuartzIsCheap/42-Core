/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:18:28 by aronez            #+#    #+#             */
/*   Updated: 2022/10/29 11:18:28 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "stack.h"

int	handle_line(t_ft_lvec *stack_a, t_ft_lvec *stack_b, const char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		stack_sa(stack_a, stack_b);
	else if (ft_strcmp(line, "sb\n") == 0)
		stack_sb(stack_a, stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		stack_ss(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		stack_ra(stack_a, stack_b);
	else if (ft_strcmp(line, "rb\n") == 0)
		stack_rb(stack_a, stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		stack_rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		stack_rra(stack_a, stack_b);
	else if (ft_strcmp(line, "rrb\n") == 0)
		stack_rrb(stack_a, stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		stack_rrr(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		stack_pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		stack_pb(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

int	execute_instructions_from_fd(t_ft_lvec *stack_a, t_ft_lvec *stack_b, int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		if (handle_line(stack_a, stack_b, line) < 0)
			return (-1);
		line = ft_get_next_line(fd);
	}
	return (0);
}

int	is_vec_sorted(const t_ft_lvec *lvec)
{
	size_t	i;

	i = 0;
	while (i < lvec->length - 1)
	{
		if (lvec->data[i] > lvec->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_ft_lvec	stack_a;
	t_ft_lvec	stack_b;

	if (argc == 1)
		return (0);
	if (parse_args_into_stack(argc, argv, &stack_a) < 0)
		return (-1);
	if (stack_a.length < 2)
		return (0);
	if (ft_lvec_with_capacity(&stack_b, stack_a.length) < 0)
		return (ft_lvec_free(&stack_a), -1);
	if (execute_instructions_from_fd(&stack_a, &stack_b, 0) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_lvec_free(&stack_b), ft_lvec_free(&stack_a), -1);
	}
	if (stack_b.length != 0 || !is_vec_sorted(&stack_a))
	{
		ft_printf("KO\n");
		return (ft_lvec_free(&stack_b), ft_lvec_free(&stack_a), -1);
	}
	ft_printf("OK\n");
	return (ft_lvec_free(&stack_b), ft_lvec_free(&stack_a), 0);
}
