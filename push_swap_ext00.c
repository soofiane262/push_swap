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

int	*ft_sorted_refa(int *refa_len, int **refs)
{
	int	i[2];
	int	*refa;

	(*refa_len) = refs[1][1];
	refa = ft_refadup(refs[1], refs[1][1]);
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

void	ft_rotate_before_push(int *i, int *len, int **a, int **b)
{
	if (len[2] - len[0] <= 2)
		ft_r(*a, len[0], "a");
	else
		ft_r_all(*a, *b, len[0], len[2] - len[0]);
	i[0]++;
	i[1]++;
}

void	ft_push(int **a, int **b, int full_len, int *len)
{
	ft_p(a, b, *len, full_len - *len);
	ft_putendl_fd("pb", 1);
	(*len)--;
}

int	*ft_make_b(int full_len, int **a, int **refs)
{
	int	i[2];
	int	len[3];
	int	*b;
	int	*refa;

	len[0] = full_len;
	len[2] = full_len;
	refa = ft_sorted_refa(&len[1], refs);
	b = (int *)malloc(sizeof(int));
	ft_exit(b, *a, refs[0], refs);
	ft_init(&i[0], &i[1], 0, 0);
	while (len[0] != len[1])
	{
		if (refa[i[1]] != i[0])
		{
			ft_push(a, &b, full_len, &len[0]);
			i[0]++;
		}
		else
			ft_rotate_before_push(i, len, a, &b);
	}
	free(refa);
	return (b);
}

int	*ft_join_rotates(int rotates_a, int rotates_b)
{
	int	*ret;

	ret = (int *)malloc(sizeof(int) * 2);
	if (!ret)
		return (NULL);
	ret[0] = rotates_a;
	ret[1] = rotates_b;
	return (ret);
}
