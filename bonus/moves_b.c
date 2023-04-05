/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:41:25 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/05 02:11:30 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	tmp = (*src);
	ft_lstadd_front(dest, ft_lstnew((*src)->content));
	(*src) = (*src)->next;
	free(tmp);
}

void	swap(t_list **head)
{
	t_list	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	rotate(t_list **head)
{
	t_list	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = *head;
	*head = (*head)->next;
	last->next->next = NULL;
}

void	rev_rotate(t_list **head)
{
	t_list	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *head;
	*head = tmp->next;
	tmp->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
