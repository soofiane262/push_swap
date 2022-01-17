/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_mvts_ext00(int *i, int **refs, int *a, int *start)
{
	while (*i + 1 < refs[1][1] && a[*i] < a[*i + 1])
		(*i)++;
	if (*i + 1 != refs[1][1] && a[*i] > a[*i + 1])
		*start = *i + 1;
	*i = *start;
}

void	ft_count_mvts_ext01(int *i, int *a, int b_j, int start)
{
	if (start && a[0] < b_j)
	{
		(*i) = 0;
		while (*i < start && a[*i] < b_j)
			(*i)++;
	}
}

void	ft_count_mvts_ext02(int *i, int full_len, int **refs, int *temp)
{
	if (i[0] != refs[1][1] && i[1] != full_len - refs[1][1]
		&& i[0] <= refs[1][1] / 2 && i[1] <= (full_len - refs[1][1]) / 2)
		while (i[0] && i[1])
		{
			(*temp)++;
			i[0]--;
			i[1]--;
		}
	else if (i[0] != refs[1][1] && i[1] != full_len - refs[1][1]
		&& i[0] > refs[1][1] / 2 && i[1] > (full_len - refs[1][1]) / 2)
		while (i[0] > refs[1][1] && i[1] > full_len - refs[1][1])
		{
			(*temp)++;
			i[0]--;
			i[1]--;
		}
	if (i[0] != refs[1][1] && i[0] <= refs[1][1] / 2)
		(*temp) += i[0];
	else if (i[0] != refs[1][1] && i[0] > refs[1][1] / 2)
		*(temp) += refs[1][1] - i[0];
	if (i[1] != full_len - refs[1][1]
		&& i[1] <= (full_len - refs[1][1]) / 2)
		(*temp) += i[1];
	else if (i[1] != full_len - refs[1][1]
		&& i[1] > (full_len - refs[1][1]) / 2)
		*(temp) += full_len - refs[1][1] - i[1];
}

void	ft_count_mvts_ext03(int *i, int **refs, int full_len, int *temp)
{
	if (*i != full_len - refs[1][1]
			&& *i <= (full_len - refs[1][1]) / 2)
		while ((*i)--)
			(*temp)++;
	else if (*i != full_len - refs[1][1]
				&& *i > (full_len - refs[1][1]) / 2)
		while ((*i)++ < full_len - refs[1][1])
			(*temp)++;
	(*temp)++;
}

int	*ft_count_mvts(int full_len, int *a, int *b, int **refs)
{
	int	i[2];
	int	j;
	int	temp[1000];
	int	*mvts;
	int	start;

	j = 0;
	while (j < 1000)
		temp[j++] = 0;
	j = 0;
	while (j != full_len - refs[1][1])
	{
		ft_init(&start, &i[0], 0);
		i[1] = j;
		ft_count_mvts_ext00(&i[0], refs, a, &start);
		while (i[0] < refs[1][1] && a[i[0]] < b[j])
			i[0]++;
		ft_count_mvts_ext01(&i[0], a, b[j], start);
		// ft_count_mvts_ext04();
		ft_count_mvts_ext02(i, full_len, refs, &temp[j]);
		// ft_count_mvts_ext03(&i[1], refs, full_len, &temp[j]);
		j++;
	}
	mvts = ft_intdup(temp, j);
	return (mvts);
}
