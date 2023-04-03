/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:35:39 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/02 02:13:37 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

t_list	*ft_lstnew(int content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(new && lst))
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

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
