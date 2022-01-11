/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:11:59 by sel-mars          #+#    #+#             */
/*   Updated: 2021/11/16 17:47:17 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
int				ft_nlsearch(char *str);
unsigned int	ft_nlidx(char *str);
char			*first_line(int fd, int *rread, char *str);
char			*next_line(int fd, int *rread, char *str);
void			ft_free(char **str);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
#endif
