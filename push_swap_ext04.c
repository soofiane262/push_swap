/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext04.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(int *x, int *y)
{
	free(x);
	free(y);
}

void	ft_p(int **x, int **y, int xlen, int ylen)
{
	int	i;
	int	temp;
	int	*ptrx;
	int	*ptry;

	temp = (*x)[0];
	i = ylen;
	ptry = ft_intdup(*y, ylen + 1);
	free(*y);
	*y = ptry;
	while (i > 0)
	{
		(*y)[i] = (*y)[i - 1];
		i--;
	}
	(*y)[0] = temp;
	ptrx = ft_intdup((*x + 1), xlen - 1);
	free(*x);
	*x = ptrx;
}

void	ft_s(int *x, char *c)
{
	int	temp;

	temp = *x;
	*x = *(x + 1);
	*(x + 1) = temp;
	ft_putendl_fd(ft_strjoin("s", c), 1);
}

void	ft_r(int *x, int xlen, char *c)
{
	int	i;
	int	temp;

	temp = x[0];
	i = 0;
	while (i < xlen - 1)
	{
		*(x + i) = *(x + i + 1);
		i++;
	}
	*(x + i) = temp;
	ft_putendl_fd(ft_strjoin("r", c), 1);
}

void	ft_rr(int *x, int xlen, char *c)
{
	int	i;
	int	temp;

	temp = x[xlen - 1];
	i = xlen - 1;
	while (i > 0)
	{
		*(x + i) = *(x + i - 1);
		i--;
	}
	*(x) = temp;
	ft_putendl_fd(ft_strjoin("rr", c), 1);
}
