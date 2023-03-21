/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:49:07 by ouakrad           #+#    #+#             */
/*   Updated: 2023/03/20 17:50:21 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_isstringdigit(char *str);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(char *str);
size_t				ft_strlen(const char *str);
long				ft_atoi(char *str);
//-----------------list---------

t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst);
