/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:04:26 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/21 15:29:51 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	do_sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	do_rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	do_rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}
