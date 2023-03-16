/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:27:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/15 12:52:01 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_three(t_list *head)
{
	int		a;
	int		b;
	int		c;

	a = head->content;
	b = head->next->content;
	c = head->next->next->content;
	if(a < b && b < c)
		return 0;
	if(a > b && b < c && c > a) //case 1
		head = swap(head);
	else if (a > b && b < c && c < a) //cae 3
		head = rotate(head);
	else if (a > b && b > c) //case 2
	{
		head = swap(head);
		head = rev_rotate(head);
	}
	else if(a < b && b > a && c < a) //case 5
		head = rev_rotate(head);
	else //case 4
	{
		head = swap(head);
		head = rotate(head);
	}
	while (head != NULL)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
	return head;
}

