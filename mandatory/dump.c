/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:27:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/03 01:16:21 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->content;
	b = (*head)->next->content;
	c = (*head)->next->next->content;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && c > a)
		do_sa(head);
	else if (a > b && b < c && c < a)
		do_ra(head);
	else if (a > b && b > c)
	{
		do_sa(head);
		do_rra(head);
	}
	else if (a < b && b > a && c < a)
		do_rra(head);
	else
	{
		do_sa(head);
		do_ra(head);
	}
}

void	four(t_list **stack_a, int first, t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while (ft_lstsize(tmp) != 3)
	{
		if (tmp->content == first)
			do_pb(stack_a, stack_b);
		else
			do_rra(stack_a);
		tmp = (*stack_a);
	}
	three(stack_a);
	do_pa(stack_a, stack_b);
	free_list(stack_b);
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
	three(stack_a);
	if ((*stack_b)->content < (*stack_b)->next->content)
		do_sb(stack_b);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
	free_list(stack_b);
}