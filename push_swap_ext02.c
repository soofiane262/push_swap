/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *ref_i, int *ref_j)
{
	int	temp;

	temp = *ref_i;
	*ref_i = *ref_j;
	*ref_j = temp;
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

int	*ft_ref(int ac, int *a)
{
	int	i;
	int	j;
	int	*ref;

	ref = (int *)malloc(sizeof(int) * (ac - 1));
	ft_exit(ref, a, NULL, NULL);
	i = 0;
	while (i < ac - 1)
	{
		ref[i] = a[i];
		i++;
	}
	i = 0;
	while (i < ac - 2)
	{
		j = i;
		while (++j < ac - 1)
			if (ref[i] > ref[j])
				ft_swap(ref + i, ref + j);
		i++;
	}
	return (ref);
}

int	*ft_refa_ext(int i, int *a, int full_len, int *tempi)
{
	int	j;
	int	*temp;

	temp = (int *)malloc(sizeof(int) * 1000);
	j = i;
	temp[0] = i;
	temp[1] = 1;
	while (++j < full_len)
	{
		if (tempi[0] < a[j])
		{
			temp[++temp[1]] = j;
			tempi[0] = a[j];
		}
	}
	j = -1;
	while (++j < i)
	{
		if (tempi[0] < a[j])
		{
			temp[++temp[1]] = j;
			tempi[0] = a[j];
		}
	}
	return (temp);
}

int	*ft_refa(int *a, int full_len)
{
	int	i;
	int	*tempi;
	int	*temp;
	int	*actual;

	tempi = (int *)malloc(sizeof(int));
	actual = (int *)malloc(sizeof(int) * 2);
	i = 0;
	actual[1] = 0;
	while (i + 1 < full_len)
	{
		tempi[0] = a[i];
		temp = ft_refa_ext(i, a, full_len, tempi);
		if (actual[1] < temp[1])
		{
			tempi = actual;
			actual = ft_intdup(temp, temp[1] + 1);
			free(tempi);
		}
		free(temp);
		i++;
	}
	return (actual);
}
