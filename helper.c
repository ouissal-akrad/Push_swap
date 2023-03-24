/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:00:06 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/24 01:12:45 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_leaks(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	print_stack(t_list *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
}

void	ftt_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	find_smallest(t_list **stack_a)
{
	t_list	**stack_b;
	int		first;
	int		second;
	int		data;
	t_list	*tmp;

	tmp = (*stack_a);
	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
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
