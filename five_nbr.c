/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:37:21 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/16 19:12:10 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_five(t_list *head)
{
	int		i;
	int		j;
	int		tmp;
	t_list	*cpy;

	i = 0;
	while (i < 5)
	{
		cpy = head;
		j = 0;
		while (j < 4 - i)
		{
			if (cpy->content > cpy->next->content)
			{
				tmp = cpy->content;
				cpy->content = cpy->next->content;
				cpy->next->content = tmp;
			}
			cpy = cpy->next;
			j++;
		}
		i++;
	}
	return (head);
}
