/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:49:07 by ouakrad           #+#    #+#             */
/*   Updated: 2023/04/05 02:07:30 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMUN_H
# define COMMUN_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
/*---------------------------libft-----------------------------*/
typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
	int				position;
}					t_list;

int					ft_isdigit(int c);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(char *str);
int					ft_strlen(const char *str);
long				ft_atoi(int pos, char **args);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_error(void);
void				free_leaks(char **args);
void				free_list(t_list **list);

/*----------------------------gnl--------------------------------*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t				ft_strlengh(char *result);
void				ft_join(char *str, char *result, char *buffer);
char				*ft_strjn(char *result, char *buffer);
char				*ft_strchr(const char *str, int c);
char				*change_result(char *result);
char				*ft_get_line(char *str);
char				*ft_get_txt(char *str, int fd);
char				*get_next_line(int fd);
#endif
