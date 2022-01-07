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

void	ft_free(int *x, int *y, char **z, char **t)
{
	int	i;

	free(x);
	free(y);
	i = 0;
	while (z[i])
	{
		free(z[i]);
		z[i] = NULL;
	}
	i = 0;
	while (t[i])
	{
		free(t[i]);
		t[i] = NULL;
	}
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

void	ft_r_all(int *a, int *b, int alen, int blen)
{
	int	i;
	int	temp;

	temp = a[0];
	i = 0;
	while (i < alen - 1)
	{
		*(a + i) = *(a + i + 1);
		i++;
	}
	*(a + i) = temp;
	temp = b[0];
	i = 0;
	while (i < blen - 1)
	{
		*(b + i) = *(b + i + 1);
		i++;
	}
	*(b + i) = temp;
	ft_putendl_fd("rr", 1);
}

void	ft_rr_all(int *a, int *b, int alen, int blen)
{
	int	i;
	int	temp;

	temp = a[alen - 1];
	i = alen - 1;
	while (i > 0)
	{
		*(a + i) = *(a + i - 1);
		i--;
	}
	*(a) = temp;
	temp = b[blen - 1];
	i = blen - 1;
	while (i > 0)
	{
		*(b + i) = *(b + i - 1);
		i--;
	}
	*(b) = temp;
	ft_putendl_fd("rrr", 1);
}
