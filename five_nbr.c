/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:37:21 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/21 15:32:04 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	helper(stack_a,first,second,stack_b);
}

void	helper(t_list **stack_a,int first,int second,t_list **stack_b)
{
	t_list	*tmp;
	int i = 0;
	tmp = (*stack_a);
	while (ft_lstsize(tmp) != 3)
	{
		if (tmp->content == first)
			do_pb(stack_a, stack_b);
		else if(tmp->content == second)
			do_pb(stack_a, stack_b);
		else
			do_rra(stack_a);
		tmp = (*stack_a);
		i++;
	}
	sort_three(stack_a);
	if((*stack_b)->content < (*stack_b)->next->content)
		do_sb(stack_b);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}
