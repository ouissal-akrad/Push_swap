/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:44:05 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/02 01:30:44 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	result(t_list *stack_a, t_list *stack_b)
{
	(void) stack_b;
	if (is_sorted(stack_a))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	exit(0);
}

void	check(t_list *stack_a, t_list *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa\n") == 0)
			swap(&stack_a);
		else if (ft_strcmp(line, "ra\n") == 0)
			rotate(&stack_a);
		else if (ft_strcmp(line, "rra\n") == 0)
			rev_rotate(&stack_a);
		else if (ft_strcmp(line, "sb\n") == 0)
			swap(&stack_b);
		else if (ft_strcmp(line, "rb\n") == 0)
			rotate(&stack_b);
		else if (ft_strcmp(line, "rrb\n") == 0)
			rev_rotate(&stack_b);
		else if (ft_strcmp(line, "ss\n") == 0)
			ss(&stack_a, &stack_b);
		else if (ft_strcmp(line, "rr\n") == 0)
			rr(&stack_a, &stack_b);
		else if (ft_strcmp(line, "rrr\n") == 0)
			rrr(&stack_a, &stack_b);
		else
			result(stack_a, stack_b);
		line = get_next_line(0);
	}
}
