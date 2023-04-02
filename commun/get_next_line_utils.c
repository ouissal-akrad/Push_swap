/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:03:46 by ouakrad           #+#    #+#             */
/*   Updated: 2022/11/21 16:13:27 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"commun.h"

size_t	ft_strlengh(char *result)
{
	int	i;

	if (!result)
		return (0);
	i = 0;
	while (result[i])
		i++;
	return (i);
}

void	ft_join(char *str, char *result, char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (result[i])
	{
		str[i] = result[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
}

char	*ft_strjn(char *result, char *buffer)
{
	char	*str;

	str = malloc(sizeof(char) * ((ft_strlengh(result) + ft_strlengh(buffer)) + 1));
	if (!str)
		return (free(result), NULL);
	if (!result)
	{
	result = malloc(sizeof(char));
		if (!result)
			return (free(result), free(str), NULL);
	result[0] = '\0';
	}
	ft_join(str, result, buffer);
	free(result);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
