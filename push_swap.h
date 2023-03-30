/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:16:45 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/30 02:57:33 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*------------parsing-----------*/
int		count_args(char *av[]);
t_list	*stack_a(char **args);
void	print_stack(t_list *head);
void	free_leaks(char **args);
/*-----------Sorting-----------*/
void	indexing(t_list *stack_a);
void	step_2(t_list *stack_a, int j);
void	step_3(t_list *stack_a, t_list *stack_b);
void	position(t_list *head);
t_list	*get_max(t_list *head);
/*------------moves-------------*/
void	swap(t_list **head);
void	rotate(t_list **head);
void	rev_rotate(t_list **head);
void	push(t_list **src, t_list **dest);
/*-----------three/five----------*/
void	three(t_list **head);
void	find_smallest(t_list **stack_a);
void	f_v(t_list **stack_a, int first, int second, t_list **stack_b);
void	five(t_list **head, int first, int second, t_list **stack_b);
void	four(t_list **stack_a, int first, t_list **stack_b);
/*--------------do--------------*/
void	do_pa(t_list **head, t_list **stack_b);
void	do_pb(t_list **head, t_list **stack_b);
void	do_sa(t_list **head);
void	do_sb(t_list **head);
void	do_ra(t_list **head);
void	do_rb(t_list **head);
void	do_rra(t_list **head);
void	do_rrb(t_list **head);
#endif
