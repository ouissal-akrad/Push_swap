/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:00:06 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/06 02:11:25 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (count_args(args) == 1)
	{
		ft_atoi(i, args);
		free_leaks(args);
		exit(0);
	}
	while (args[i] != NULL)
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(i, args) == ft_atoi(j, args))
			{
				free_leaks(args);
				ft_error();
			}
			j++;
		}
		i++;
	}
}
