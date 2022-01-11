/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:27:08 by sel-mars          #+#    #+#             */
/*   Updated: 2021/11/16 23:15:26 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*newstr;

	newstr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!str || !newstr)
	{
		free(newstr);
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*newstr;

	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1 || !s2 || !newstr)
	{
		free(newstr);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	unsigned int	newlen;
	char			*newstr;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	newlen = ft_strlen(s) - start + 1;
	if (len < newlen)
		newlen = len;
	newstr = (char *)malloc((newlen + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < newlen)
		newstr[i++] = s[start++];
	newstr[i] = '\0';
	return (newstr);
}
