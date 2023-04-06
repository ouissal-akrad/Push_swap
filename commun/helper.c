/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:08:13 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/06 02:37:16 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

void	free_leaks(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	ret = malloc((ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_all_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r'
			&& *str != '\f' && *str != '\v')
			return (0);
		str++;
	}
	return (1);
}
