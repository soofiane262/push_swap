/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:26:34 by sel-mars          #+#    #+#             */
/*   Updated: 2021/11/16 23:15:03 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_nlsearch(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

unsigned int	ft_nlidx(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*first_line(int fd, int *rread, char *str)
{
	char	*buff;
	char	*temp;

	*rread = BUFFER_SIZE;
	if (!str)
	{
		buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		*rread = read(fd, buff, BUFFER_SIZE);
		if (*rread)
		{
			buff[*rread] = '\0';
			temp = str;
			str = ft_strdup(buff);
			ft_free(&temp);
		}
		ft_free(&buff);
	}
	return (str);
}

char	*next_line(int fd, int *rread, char *str)
{
	char	*buff;
	char	*temp;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (str && !ft_nlsearch(str) && *rread == BUFFER_SIZE)
	{
		*rread = read(fd, buff, BUFFER_SIZE);
		buff[*rread] = '\0';
		temp = str;
		str = ft_strjoin(str, buff);
		free(temp);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str[1024];
	char			*temp;
	char			*rslt;
	int				rread;
	unsigned int	nlidx;

	rslt = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) != 0)
		return (NULL);
	str[fd] = first_line(fd, &rread, str[fd]);
	str[fd] = next_line(fd, &rread, str[fd]);
	if (str[fd] && !ft_nlsearch(str[fd]))
	{
		rslt = ft_strdup(str[fd]);
		ft_free(&str[fd]);
	}
	else if (str[fd] && ft_nlsearch(str[fd]))
	{
		nlidx = ft_nlidx(str[fd]);
		rslt = ft_substr(str[fd], 0, nlidx + 1);
		temp = str[fd];
		str[fd] = ft_substr(str[fd], nlidx + 1, ft_strlen(str[fd]));
		free(temp);
	}
	return (rslt);
}
