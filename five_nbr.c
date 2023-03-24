/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:37:21 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/23 22:53:25 by ouakrad          ###   ########.fr       */
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
	if(ft_lstsize(*stack_a) == 100)
		four(stack_a, first, second, stack_b);
	if(ft_lstsize(*stack_a) == 5)
		five(stack_a, first, second, stack_b);
	if(ft_lstsize(*stack_a) == 4)
		four(stack_a, first, second, stack_b);
}

void four(t_list **stack_a, int first, int second, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while (ft_lstsize(tmp) != 2)
	{
		if (tmp->content == first)
			do_pb(stack_a, stack_b);
		else if (tmp->content == second)
			do_pb(stack_a, stack_b);
		else
			do_rra(stack_a);
		tmp = (*stack_a);
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		do_sa(stack_a);
	if ((*stack_b)->content < (*stack_b)->next->content)
		do_sb(stack_b);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
	print_stack(*stack_a);
}

void	five(t_list **stack_a, int first, int second, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while (ft_lstsize(tmp) != 3)
	{
		if (tmp->content == first)
			do_pb(stack_a, stack_b);
		else if (tmp->content == second)
			do_pb(stack_a, stack_b);
		else
			do_rra(stack_a);
		tmp = (*stack_a);
	}
	sort_three(stack_a);
	if ((*stack_b)->content < (*stack_b)->next->content)
		do_sb(stack_b);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}
