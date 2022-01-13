/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ext00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p_checker(int **x, int **y, int xlen, int ylen)
{
	int	i;
	int	temp;
	int	*ptrx;
	int	*ptry;

	temp = (*x)[0];
	i = ylen;
	ptry = ft_intdup2(*y, ylen + 1);
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

void	ft_s_checker(int *x)
{
	int	temp;

	temp = *x;
	*x = *(x + 1);
	*(x + 1) = temp;
}

void	ft_s_all_checker(int **x, int **y)
{
	ft_s_checker(*x);
	ft_s_checker(*y);
}

void	ft_r_checker(int *x, int xlen)
{
	int		i;
	int		temp;

	temp = x[0];
	i = 0;
	while (i < xlen - 1)
	{
		*(x + i) = *(x + i + 1);
		i++;
	}
	*(x + i) = temp;
}

void	ft_rr_checker(int *x, int xlen)
{
	int		i;
	int		temp;

	temp = x[xlen - 1];
	i = xlen - 1;
	while (i > 0)
	{
		*(x + i) = *(x + i - 1);
		i--;
	}
	*x = temp;
}
