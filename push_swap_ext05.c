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

char	**ft_sort_ext01(int full_len, int **refs, int **min)
{
	int		i[2];
	char	*temp[1000];
	char	**rotates_b;

	i[0] = 0;
	if ((*min)[1] <= (full_len - refs[1][1]) / 2)
	{
		i[1] = -1;
		while (++i[1] < (*min)[1] && (*min)[0]-- >= 0)
			temp[i[0]++] = "rb";
	}
	else
	{
		i[1] = (*min)[1] - 1;
		while (++i[1] < full_len - refs[1][1] && (*min)[0]-- >= 0)
			temp[i[0]++] = "rrb";
	}
	(*min)[0]--;
	rotates_b = (char **)malloc(sizeof(char *) * i[0] + 1);
	i[1] = -1;
	while (++i[1] < i[0])
		rotates_b[i[1]] = ft_strdup(temp[i[1]]);
	rotates_b[i[1]] = NULL;
	return (rotates_b);
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

char	**ft_sort_ext04(int *ii, int *j, int **min, int **refs)
{
	int		i[2];
	char	*temp[1000];
	char	**rotates_a;

	while (*ii != refs[1][1] && *ii <= refs[1][1] / 2 && (*ii)--)
			(*j)++;
	i[0] = 0;
	if (*j == *min[0])
		while (--(*min)[0] >= 0)
			temp[i[0]++] = "ra";
	else
		while (--(*min)[0] >= 0)
			temp[i[0]++] = "rra";
	rotates_a = (char **)malloc(sizeof(char *) * i[0] + 1);
	i[1] = -1;
	while (++i[1] < i[0])
		rotates_a[i[1]] = ft_strdup(temp[i[1]]);
	rotates_a[i[1]] = NULL;
	return (rotates_a);
}
