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

int	*ft_sort_ext00(int full_len, int **refs, int *mvts)
{
	int	i;
	int	*min;

	min = (int *)malloc(sizeof(int) * 2);
	min[0] = mvts[0];
	min[1] = 0;
	i = 0;
	while (i < full_len - refs[1][1])
	{
		if (mvts[i] <= min[0])
		{
			min[0] = mvts[i];
			min[1] = i;
		}
		i++;
	}
	return (min);
}

int	ft_sort_ext01(int full_len, int **refs, int **min)
{
	int	i[2];
	int	count;

	i[0] = 0;
	count = 0;
	if ((*min)[1] <= (full_len - refs[1][1]) / 2)
	{
		i[1] = -1;
		while (++i[1] < (*min)[1])
			count++;
	}
	else
	{
		i[1] = (*min)[1] - 1;
		while (++i[1] < full_len - refs[1][1])
			count--;
	}
	return (count);
}

void	ft_sort_ext02(int *i, int *start, int **a, int **refs)
{
	while (*i + 1 < refs[1][1] && (*a)[*i] < (*a)[*i + 1])
		(*i)++;
	if (*i + 1 != refs[1][1] && (*a)[*i] > (*a)[*i + 1])
		*start = *i + 1;
	*i = *start;
}

void	ft_sort_ext03(int *i, int *start, int **a, int b_min)
{
	if (*start && (*a)[0] < b_min)
	{
		*i = 0;
		while (*i < *start && (*a)[*i] < b_min)
			(*i)++;
	}
}

int	ft_sort_ext04(int *i, int alen)
{
	int	count;

	count = 0;
	if (*i <= alen / 2)
		count = *i;
	else
		count = (alen - *i) * -1;
	return (count);
}
