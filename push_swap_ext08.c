/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext08.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(int *x, char *c)
{
	int		temp;
	char	*s;

	temp = *x;
	*x = *(x + 1);
	*(x + 1) = temp;
	s = ft_strjoin("s", c);
	if (!s)
		return ;
	ft_putendl_fd(s, 1);
	free(s);
}

int	*ft_intdup(int *x, int len)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *)malloc(len * sizeof(int));
	if (!cpy)
		return (0);
	while (i < len)
	{
		cpy[i] = x[i];
		i++;
	}
	return (cpy);
}

int	*ft_intdup2(int *x, int len)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *)malloc(len * sizeof(int));
	if (!cpy)
		return (0);
	while (i < len - 1)
	{
		cpy[i] = x[i];
		i++;
	}
	return (cpy);
}
