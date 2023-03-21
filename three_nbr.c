/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:27:16 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/20 16:11:51 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->content;
	b = (*head)->next->content;
	c = (*head)->next->next->content;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && c > a) //case 1
		do_sa(head);
	else if (a > b && b < c && c < a) //cae 3
		do_ra(head);
	else if (a > b && b > c) //case 2
	{
		do_sa(head);
		do_rra(head);
	}
	else if (a < b && b > a && c < a) //case 5
		do_rra(head);
	else //case 4
	{
		do_sa(head);
		do_ra(head);
	}
	// print_stack(*head);
}
