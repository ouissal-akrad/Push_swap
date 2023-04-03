/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:00:06 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/03 01:32:15 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_leaks(char **args)
{
	int	i;

	i = 0;
	while (args)
		free(args[i++]);
	free(args);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

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

void	print_stack(t_list *head)
{
	while (head != NULL)
	{
		printf("content : %d\n", head->content);
		head = head->next;
	}
}

void	find_smallest(t_list **stack_a, t_list **stack_b)
{
	int		first;
	int		second;
	int		data;
	t_list	*tmp;

	tmp = (*stack_a);
	first = INT_MAX;
	second = INT_MAX;
	while (tmp != NULL)
	{
		data = tmp->content;
		if (data < first)
		{
			second = first;
			first = data;
		}
		else if (data < second && data != first)
			second = data;
		tmp = tmp->next;
	}
	f_v(stack_a, first, second, stack_b);
}

void	f_v(t_list **stack_a, int first, int second, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 5)
		five(stack_a, first, second, stack_b);
	if (ft_lstsize(*stack_a) == 4)
		four(stack_a, first, stack_b);
}
