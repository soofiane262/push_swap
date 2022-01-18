/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext06.c                                  :+:      :+:    :+:   */
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
	if (x)
		free(x);
	if (y)
		free(y);
	if (z)
		ft_free_arr(z);
	if (t)
		ft_free_arr(t);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	ft_init(int *i, int *j, int *k, int *l)
{
	*i = 0;
	if (j)
		*j = 0;
	if (k)
		*k = 0;
	if (l)
		*l = 0;
}

void	ft_putnbrs(int len, int *x)
{
	int	i;

	ft_putstr_fd("	. :", 1);
	i = 0;
	while (i < len)
	{
		ft_putstr_fd(" | ", 1);
		ft_putnbr_fd(x[i++], 1);
	}
	ft_putstr_fd(" | : .\n\n", 1);
}

void	ft_join_lens(int **min, int alen, int blen)
{
	free(*min);
	(*min) = (int *)malloc(sizeof(int) * 2);
	if (!(*min))
		return ;
	(*min)[0] = alen;
	(*min)[1] = blen;
}
