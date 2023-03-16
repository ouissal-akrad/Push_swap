/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:16:45 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/16 12:35:20 by ouakrad          ###   ########.fr       */
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

/*------------Libft------------*/

void	ftt_error(void);
int		count_args(char *av[]);
t_list	*stack_a(char **args);
t_list	*swap(t_list *head);
t_list	*rotate(t_list *head);
t_list	*rev_rotate(t_list *head);
t_list	*push(t_list *head);
t_list	*sort_three(t_list *head);
t_list	*sort_five(t_list *head);
void	print_stack(t_list *head);
#endif
