/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sorted_refa(int *refa_len, int full_len, int *a, int **refs)
{
	int	i[2];
	int	*temp;
	int	*refa;

	temp = ft_refa(a, full_len, refs);
	(*refa_len) = temp[1];
	temp[1] = temp[0];
	refa = ft_intdup(temp + 1, *refa_len);
	free(temp);
	i[0] = 0;
	while (i[0] < *refa_len)
	{
		i[1] = i[0] + 1;
		while (i[1] < *refa_len)
		{
			if (refa[i[1]] < refa[i[0]])
				ft_swap(refa + i[1], refa + i[0]);
			i[1]++;
		}
		i[0]++;
	}
	return (refa);
}

void	ft_rotate_before_push(int *i, int *len, int **a, int *refa)
{
	i[2] = 0;
	while (i[1] + 1 < len[1] && refa[i[1]] + 1 == refa[i[1] + 1])
	{
		i[1]++;
		i[2]++;
	}
	i[1]++;
	if (i[2] + 1 <= len[0] / 2)
	{
		while (i[2] >= 0)
		{
			ft_r(*a, len[0], "a");
			i[2]--;
			i[0]++;
		}
	}
	else
	{
		while (i[2] + 1 < len[0])
		{
			ft_rr(*a, len[0], "a");
			i[2]++;
			i[0]++;
		}
	}
}

void	ft_push(int **a, int **b, int full_len, int *len)
{
	ft_p(a, b, *len, full_len - *len);
	ft_putendl_fd("pb", 1);
	(*len)--;
}

int	*ft_make_b(int full_len, int **a, int **refs)
{
	int	i[3];
	int	len[2];
	int	*b;
	int	*refa;

	len[0] = full_len;
	refa = ft_sorted_refa(&len[1], full_len, *a, refs);
	b = (int *)malloc(sizeof(int));
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (len[0] != len[1])
	{
		if (refa[i[1]] == i[0])
			ft_rotate_before_push(i, len, a, refa);
		else
		{
			ft_push(a, &b, full_len, &len[0]);
			i[0]++;
		}
	}
	free(refa);
	return (b);
}

char	***ft_join_rotates(char **rotates_a, char **rotates_b)
{
	int		i[2];
	char	***ret;

	ft_init(&i[0], &i[1], 0);
	while (rotates_a[i[0]])
		i[0]++;
	while (rotates_b[i[1]])
		i[1]++;
	ret = (char ***)malloc(sizeof(char **) * 2);
	ret[0] = (char **)malloc(sizeof(char *) * (i[0] + 1));
	ret[1] = (char **)malloc(sizeof(char *) * (i[1] + 1));
	ft_init(&i[0], &i[1], 0);
	while (rotates_a[i[1]])
		ret[0][i[0]++] = ft_strdup(rotates_a[i[1]++]);
	ret[0][i[0]] = NULL;
	ft_init(&i[0], &i[1], 0);
	while (rotates_b[i[1]])
		ret[1][i[0]++] = ft_strdup(rotates_b[i[1]++]);
	ret[1][i[0]] = NULL;
	return (ret);
}
