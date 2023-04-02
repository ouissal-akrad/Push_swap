/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:31:10 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/01 01:10:55 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

void	ft_error(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

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

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	value;

	i = 0;
	sign = 1;
	value = 0;
	while (str[i] == 32)
		i++;
	if (!str[i])
		ft_error();
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!str[i])
		ft_error();
	while (str[i] && ft_isdigit(str[i]))
	{
		value = value * 10 + str[i++] - '0';
		if ((value > 2147483647 && sign == 1) || (value > 2147483648 && sign
				== -1))
			ft_error();
	}
	if (str[i])
		ft_error();
	return (value * sign);
}
