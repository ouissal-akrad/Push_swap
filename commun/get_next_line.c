/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:11:41 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/01 01:39:21 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"commun.h"

char	*change_result(char *result)
{
	int		i;
	int		j;
	char	*new_result;

	i = 0;
	j = 0;
	while (result[i] != '\0' && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		i++;
	if (result[i] == 0)
	{
		free (result);
		return (NULL);
	}
	new_result = (char *)malloc(sizeof(char) * (ft_strlengh(result) - i + 1));
	if (!new_result)
		return (NULL);
	while (result[i] != '\0')
		new_result[j++] = result[i++];
	new_result[j] = 0;
	free(result);
	return (new_result);
}

char	*ft_get_line(char *result)
{
	int			len;
	char		*line;
	int			j;

	len = 0;
	j = 0;
	if (result[0] == '\0')
		return (NULL);
	while (result[len] != '\0' && result[len] != '\n')
		len++;
	if (result[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (j < len)
	{
		line[j] = result[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*ft_get_txt(char *result, int fd)
{
	char	*buffer;
	int		read_ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_ret = 1;
	while (1)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_ret] = 0;
		result = ft_strjn(result, buffer);
		if (ft_strchr(result, '\n') != NULL || read_ret == 0)
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*line;

	if (result && read(fd, NULL, 0) == -1)
		return (free(result), result = NULL, NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = ft_get_txt(result, fd);
	if (result == NULL)
		return (NULL);
	line = ft_get_line(result);
	result = change_result(result);
	return (line);
}
