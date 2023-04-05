/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:31:10 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/05 02:10:37 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(int pos, char **args)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	sign = 1;
	value = 0;
	while (args[pos][i] == 32)
		i++;
	if (!args[pos][i])
	{
		free_leaks(args);
		ft_error();
	}
	if (args[pos][i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (args[pos][i] == '+')
		i++;
	if (!args[pos][i])
	{
		free_leaks(args);
		ft_error();
	}
	while (args[pos][i] && ft_isdigit(args[pos][i]))
	{
		value = value * 10 + args[pos][i++] - '0';
		if ((value > 2147483647 && sign == 1) || (value > 2147483648 && sign
				== -1))
		{
			free_leaks(args);
			ft_error();
		}
	}
	if (args[pos][i])
	{
		free_leaks(args);
		ft_error();
	}
	return (value * sign);
}
