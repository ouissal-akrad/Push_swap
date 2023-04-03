/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:04:28 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/02 21:41:57 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../commun/commun.h"
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
int		is_sorted(t_list *stack_a);
char	*ft_strtrim(char const *s1, char const *set);
/*-----------checker-----------*/
void	result(t_list *stack_a, t_list *stack_b);
void	check(t_list *stack_a, t_list *stack_b);
/*------------moves-------------*/
void	swap(t_list **head);
void	rotate(t_list **head);
void	rev_rotate(t_list **head);
void	push(t_list **src, t_list **dest);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
#endif
