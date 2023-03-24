/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:45:34 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/24 01:01:57 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_leaks(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	print_stack(t_list *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
}

void	ftt_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

int	count_args(char *av[])
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	**valid(int j, char **av)
{
	int		i;
	char	*new_arg;
	char	*tmp;
	char	**args;

	i = 1;
	new_arg = ft_strdup("");
	while (i < j)
	{
		tmp = new_arg;
		av[i] = ft_strjoin(av[i], " ");
		new_arg = ft_strjoin(new_arg, av[i++]);
		free(tmp);
	}
	args = ft_split(new_arg, ' ');
	free(new_arg);
	return (args);
}

void	go(t_list *stack_a)
{
	if (ft_lstsize(stack_a) == 3)
		three(&stack_a);
	if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
		find_smallest(&stack_a);
}

t_list	*stack_a(char **args)
{
	int		i;
	t_list	*stack_a;
	t_list	*new;

	i = 0;
	if (count_args(args) == 0)
		return (NULL);
	stack_a = ft_lstnew(ft_atoi(args[i]));
	while (args[++i] != NULL)
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(&stack_a, new);
	}
	go(stack_a);
	return (stack_a);
}

int	main(int ac, char *av[])
{
	int		i;
	int		j;
	char	**args;

	args = valid(ac, av);
	i = 0;
	j = 0;
	if (count_args(args) == 1)
		ft_atoi(args[i]);
	while (args[i] != NULL)
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				ftt_error();
			j++;
		}
		i++;
	}
	if (stack_a(args) == NULL)
		exit(0);
	return (0);
}
