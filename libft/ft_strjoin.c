/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:34:35 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/02 13:01:57 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pnt;
	size_t	i_pref;
	size_t	i_suf;
	size_t	j;

	if (!(s1 && s2))
		return (NULL);
	pnt = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!pnt)
		return (NULL);
	j = 0;
	i_pref = 0;
	while (s1[i_pref])
		pnt[j++] = s1[i_pref++];
	i_suf = 0;
	while (s2[i_suf])
		pnt[j++] = s2[i_suf++];
	pnt[j] = '\0';
	return (pnt);
}
