/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:00:06 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/24 01:00:17 by ouakrad          ###   ########.fr       */
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
	if(ft_lstsize(*stack_a) == 5)
		five(stack_a, first, second, stack_b);
	if(ft_lstsize(*stack_a) == 4)
		four(stack_a, first, stack_b);
}
