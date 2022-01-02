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

int	*ft_refa(int len, int *ref, int *a)
{
	int	i;
	int	var;
	int	*refa;

	var = len / 2;
	refa = (int *)malloc(sizeof(int) * var);
	ft_exit(refa, a, ref, NULL);
	if (var * 2 != len)
		var++;
	i = 0;
	while (var < len)
		refa[i++] = ref[var++];
	return (refa);
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
