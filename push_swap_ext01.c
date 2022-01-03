/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_len(int x, char c)
{
	int	ret;

	ret = x / 2;
	if (ret * 2 != x && c == 'b')
		ret++;
	return (ret);
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
				ft_swap(ref + i, ref + j, ref[i]);
		i++;
	}
	return (ref);
}

int	*ft_refa(int *ref, int *a, int full_len)
{
	int	i;
	int	j;
	int	temp[2];
	int	*actual;

	actual = (int *)malloc(sizeof(int));
	i = 0;
	actual[0] = 0;
	actual[1] = 0;
	while(i < full_len)
	{
		j = 0;
		temp[0] = i;
		temp[1] = 0;
		while (a[i] && ref[j] && a[i] != ref[j])
			j++;
		while (a[i] && ref[j] && a[i] == ref[j])
		{
			temp[1]++;
			i++;
			j++;
		}
		if (actual[1] < temp[1])
		{
			actual[0] = temp[0];
			actual[1] = temp[1];
		}
		if (a[i] && ref[j] && a[i] == ref[j])
			i++;
	}
	return (actual);
}

int	*ft_refb(int len, int *ref, int *a)
{
	int	i;
	int	j;
	int	var;
	int	*refb;

	var = len / 2;
	refb = (int *)malloc(sizeof(int) * var);
	ft_exit(refb, a, ref, NULL);
	if (var * 2 != len)
		var++;
	j = var - 1;
	i = 0;
	while (i < var)
		refb[i++] = ref[j--];
	return (refb);
}
