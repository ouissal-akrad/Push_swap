/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:27:56 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/05 02:14:41 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list *stack_a)
{
	t_list	*head;
	t_list	*compare;
	int		j;

	if (stack_a)
	{
		head = stack_a;
		while (head)
		{
			j = 0;
			compare = stack_a;
			while (compare)
			{
				if (head->content > compare->content)
					j++;
				compare = compare->next;
			}
			head->index = j;
			head = head->next;
		}
	}
}

void	position(t_list *head)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = head;
	while (temp)
	{
		temp->position = i++;
		temp = temp->next;
	}
}

t_list	*get_max(t_list *head)
{
	t_list	*max;
	t_list	*current;

	max = head;
	current = head;
	while (current)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

void	step_2(t_list *stack_a, t_list *stack_b, int j)
{
	int	i;

	indexing(stack_a);
	i = 0;
	while (stack_a)
	{
		if ((stack_a)->index < i)
		{
			do_pb(&stack_a, &stack_b);
			i++;
		}
		else if ((stack_a)->index <= i + j)
		{
			do_pb(&stack_a, &stack_b);
			do_rb(&stack_b);
			i++;
		}
		else
			do_ra(&stack_a);
	}
	step_3(stack_a, stack_b);
}

void	step_3(t_list *stack_a, t_list *stack_b)
{
	int	m_position;

	while (stack_b)
	{
		position(stack_b);
		m_position = get_max(stack_b)->position;
		if (m_position > ft_lstsize(stack_b) / 2)
		{
			m_position = ft_lstsize(stack_b) - m_position + 2;
			while (--m_position)
				do_rrb(&stack_b);
			do_pa(&stack_a, &stack_b);
		}
		else
		{
			m_position = get_max(stack_b)->position;
			while (--m_position)
				do_rb(&stack_b);
			do_pa(&stack_a, &stack_b);
		}
	}
	free_list(&stack_a);
	free_list(&stack_b);
}
