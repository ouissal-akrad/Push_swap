/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:44:05 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/06 02:09:35 by ouakrad          ###   ########.fr       */
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

void	invalid(t_list **stack_a, t_list **stack_b)
{
	free_list(stack_a);
	free_list(stack_b);
	ft_error();
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

void	handler(t_list **stack_a, t_list **stack_b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(command, "pa") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(command, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(command, "rra") == 0)
		rev_rotate(stack_a);
	else if (ft_strcmp(command, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(command, "pb") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(command, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(command, "rrb") == 0)
		rev_rotate(stack_b);
	else if (ft_strcmp(command, "ss") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(command, "rr") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(stack_a, stack_b);
	else
		invalid(stack_a, stack_b);
}

void	check(t_list *stack_a, t_list *stack_b)
{
	char	*line;
	char	*new;

	line = get_next_line(0);
	while (line)
	{
		new = ft_strtrim(line, "\n");
		handler(&stack_a, &stack_b, new);
		free(new);
		free(line);
		line = get_next_line(0);
	}
	result(stack_a, stack_b);
}
