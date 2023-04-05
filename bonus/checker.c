/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:44:05 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/05 02:05:15 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	result(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	free_list(&stack_a);
	free_list(&stack_b);
	exit(0);
}

void	check(t_list *stack_a, t_list *stack_b)
{
	char	*line;
	char	*new;

	line = get_next_line(0);
	while (line)
	{
		new = ft_strtrim(line, "\n");
		if (ft_strcmp(new, "sa") == 0)
			swap(&stack_a);
		else if (ft_strcmp(new, "pa") == 0)
			push(&stack_b, &stack_a);
		else if (ft_strcmp(new, "ra") == 0)
			rotate(&stack_a);
		else if (ft_strcmp(new, "rra") == 0)
			rev_rotate(&stack_a);
		else if (ft_strcmp(new, "sb") == 0)
			swap(&stack_b);
		else if (ft_strcmp(new, "pb") == 0)
			push(&stack_a, &stack_b);
		else if (ft_strcmp(new, "rb") == 0)
			rotate(&stack_b);
		else if (ft_strcmp(new, "rrb") == 0)
			rev_rotate(&stack_b);
		else if (ft_strcmp(new, "ss") == 0)
			ss(&stack_a, &stack_b);
		else if (ft_strcmp(new, "rr") == 0)
			rr(&stack_a, &stack_b);
		else if (ft_strcmp(new, "rrr") == 0)
			rrr(&stack_a, &stack_b);
		else
		{
			free_list(&stack_a);
			free_list(&stack_b);
			ft_error();
		}
		line = get_next_line(0);
	}
	result(stack_a, stack_b);
}
