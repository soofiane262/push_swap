/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext05.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_ext00(int *i, int full_len, int **refs, int *mvts)
{
	int	*min;

	min = (int *)malloc(sizeof(int) * 2);
	min[0] = mvts[0];
	min[1] = 0;
	while (*i < full_len - refs[1][1])
	{
		if (mvts[*i] < min[0])
		{
			min[0] = mvts[*i];
			min[1] = *i;
		}
		(*i)++;
	}
	return (min);
}

void	ft_sort_ext01(int **b, int full_len, int **refs, int **min)
{
	if ((*min)[1] <= (full_len - refs[1][1]) / 2)
	{
		while ((*min)[1] > 0)
		{
			ft_r(*b, full_len - refs[1][1], "b");
			(*min)[0]--;
			(*min)[1]--;
		}
	}
	else
	{
		while ((*min)[1] < full_len - refs[1][1])
		{
			ft_rr(*b, full_len - refs[1][1], "b");
			(*min)[0]--;
			(*min)[1]++;
		}
	}
	(*min)[0]--;
}

void	ft_sort_ext02(int *i, int *start, int **a, int **refs)
{
	while (*i + 1 < refs[1][1] && (*a)[*i] < (*a)[*i + 1])
		(*i)++;
	if (*i + 1 != refs[1][1] && (*a)[*i] > (*a)[*i + 1])
		*start = *i + 1;
	*i = *start;
}

void	ft_sort_ext03(int *i, int *start, int **a, int **b)
{
	if (*start && (*a)[0] < (*b)[0])
	{
		*i = 0;
		while (*i < *start && (*a)[*i] < (*b)[0])
			(*i)++;
	}
}

void	ft_sort_ext04(int j, int **min, int **a, int **refs)
{
	if (j == *min[0])
	{
		while (*min[0] > 0)
		{
			ft_r(*a, refs[1][1], "a");
			(*min)[0]--;
		}
	}
	else
	{
		while (*min[0] > 0)
		{
			ft_rr(*a, refs[1][1], "a");
			(*min)[0]--;
		}
	}
}
