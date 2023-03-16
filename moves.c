/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:42:48 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/16 19:22:13 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *head)
{
	t_list	*tmp;

	if (head == NULL || head->next == NULL)
		return (head);
	tmp = head->next;
	head->next = tmp->next;
	tmp->next = head;
	head = tmp;
	write(1, "sa\n", 3);
	return (head);
}
t_list *push(t_list *head)
{
	t_list *tmp;

	tmp = head;
	if(head == NULL || head->next == NULL)
		return (head);
	while ()
	{
		/* code */
	}
	
}
t_list	*rotate(t_list *head)
{
	t_list	*last;

	last = head;
	if (head == NULL || head->next == NULL)
		return (head);
	while (last->next)
		last = last->next;
	last->next = head;
	head = head->next;
	last->next->next = NULL;
	write(1, "ra\n", 3);
	return (head);
}

t_list	*rev_rotate(t_list *head)
{
	t_list	*last;

	last = head;
	if (head == NULL || head->next == NULL)
		return (head);
	while (last->next)
		last = last->next;
	last->next = head;
	head = last;
	while (head->next != last)
		head = head->next;
	head->next = NULL;
	write(1, "rra\n", 4);
	return (last);
}
