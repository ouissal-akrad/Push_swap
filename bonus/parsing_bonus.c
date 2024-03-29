/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:57:58 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/06 23:42:14 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	go(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	check(stack_a, stack_b);
}

t_list	*stack_a(char **args)
{
	int		i;
	t_list	*stack_a;

	i = 0;
	if (count_args(args) == 0)
		return (NULL);
	stack_a = ft_lstnew(ft_atoi(i, args));
	while (args[++i] != NULL)
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(i, args)));
	free_leaks(args);
	go(stack_a);
	return (stack_a);
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
		if (ft_strlen(av[i]) == 0 || ft_all_spaces(av[i]))
		{
			free(new_arg);
			ft_error();
		}
		tmp = new_arg;
		av[i] = ft_strjoin(av[i], " ");
		new_arg = ft_strjoin(new_arg, av[i]);
		free(av[i++]);
		free(tmp);
	}
	args = ft_split(new_arg, ' ');
	free(new_arg);
	return (args);
}

int	main(int ac, char *av[])
{
	char	**args;

	args = valid(ac, av);
	check_2(args);
	if (stack_a(args) == NULL)
	{
		free_leaks(args);
		exit(0);
	}
	return (0);
}
