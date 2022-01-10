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

int	*ft_ref(int ac, int *a, int **refs)
{
	int	i;
	int	j;
	int	*ref;

	ref = (int *)malloc(sizeof(int) * (ac - 1));
	ft_exit(ref, a, NULL, refs);
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

int	*ft_refa_ext00(int i, int *a, int full_len, int t)
{
	int	j;
	int	*temp;

	temp = (int *)malloc(sizeof(int) * 1000);
	j = i;
	temp[0] = i;
	temp[1] = 1;
	while (++j < full_len)
		if (t < a[j])
			ft_refa_ext01(&temp[++temp[1]], j, &t, a[j]);
	j = -1;
	while (++j < i)
		if (t < a[j])
			ft_refa_ext01(&temp[++temp[1]], j, &t, a[j]);
	return (temp);
}

void	ft_refa_ext01(int *x, int y, int *z, int t)
{
	*x = y;
	*z = t;
}


int	*ft_refa(int *a, int full_len)
{
	int	i[2];
	int	*tempi;
	int	*temp;
	int	*actual;

	actual = (int *)malloc(sizeof(int) * 2);
	ft_init(&i[0], &actual[0], &actual[1]);
	while (++i[0] < full_len)
	{
		i[1] = a[i[0]];
		temp = ft_refa_ext00(i[0], a, full_len, i[1]);
		if (actual[1] < temp[1])
		{
			tempi = actual;
			actual = ft_intdup(temp, temp[1] + 1);
			free(tempi);
		}
		free(temp);
		i[0]++;
	}
	return (actual);
}
