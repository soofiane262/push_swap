/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext07.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_sort(int **a, int **refs, int full_len)
{
	int	i[3];
	int	start;

	ft_init(&i[0], &i[1], &i[2]);
	start = 0;
	while (start < full_len && (*a)[start] != refs[0][0])
		start++;
	i[0] = start;
	while (i[0] < full_len && (*a)[i[0]] == refs[0][i[1]])
		if (++i[0])
			i[1]++;
	while (i[2] < start && (*a)[i[2]] == refs[0][i[1]])
	{
		i[1]++;
		i[2]++;
	}
	ft_check_sort_ext(a, i[2], start, full_len);
	if ((!start && i[0] == full_len) || (start && i[2] == start))
	{
		ft_free(*a, refs[0], NULL, NULL);
		if (refs[1])
			free(refs[1]);
		free(refs);
		exit(0);
	}
}

void	ft_check_sort_ext(int **a, int i, int start, int full_len)
{
	if (i == start)
	{
		if (start <= full_len / 2)
			while (start--)
				ft_r(*a, full_len, "a");
		else
			while (start++ < full_len)
				ft_rr(*a, full_len, "a");
	}
}

void	ft_final_rotate(int **a, int **refs)
{
	int	i;

	i = 0;
	while ((*a)[i] != refs[0][0])
		i++;
	if (i <= refs[1][1] / 2)
		while (i--)
			ft_r(*a, refs[1][1], "a");
	else
		while (i++ < refs[1][1])
			ft_rr(*a, refs[1][1], "a");
}

void	ft_rotates(int **a, int **b, int *r, int *lens)
{
	if (!r)
		return ;
	while (r[0] > 0 && r[1] > 0)
		if (r[0]-- > 0 && r[1]-- > 0)
			ft_r_all(*a, *b, lens[0], lens[1]);
	while (r[0] < 0 && r[1] < 0)
		if (r[0]++ < 0 && r[1]++ < 0)
			ft_rr_all(*a, *b, lens[0], lens[1]);
	while (r[0] > 0)
		if (r[0]-- > 0)
			ft_r(*a, lens[0], "a");
	while (r[0] < 0)
		if (r[0]++ < 0)
			ft_rr(*a, lens[0], "a");
	while (r[1] > 0)
		if (r[1]-- > 0)
			ft_r(*b, lens[1], "b");
	while (r[1] < 0)
		if (r[1]++ < 0)
			ft_rr(*b, lens[1], "b");
	free(r);
}

void	ft_sort(int full_len, int **a, int **b, int **refs)
{
	int	i[3];
	int	*min;
	int	*mvts;
	int	rotates_a;
	int	rotates_b;

	while (refs[1][1] != full_len)
	{
		i[0] = 0;
		mvts = ft_count_mvts(full_len, *a, *b, refs);
		min = ft_sort_ext00(&i[0], full_len, refs, mvts);
		rotates_b = ft_sort_ext01(full_len, refs, &min);
		ft_init(&i[0], &i[1], &i[2]);
		ft_sort_ext02(&i[0], &i[2], a, refs);
		while (i[0] < refs[1][1] && (*a)[i[0]] < (*b)[min[1]])
			i[0]++;
		ft_sort_ext03(&i[0], &i[2], a, (*b)[min[1]]);
		rotates_a = ft_sort_ext04(&i[0], &i[1], &min, refs);
		ft_join_lens(&min, refs[1][1], full_len - refs[1][1]);
		ft_rotates(a, b, ft_join_rotates(rotates_a, rotates_b), min);
		ft_p(b, a, full_len - refs[1][1], refs[1][1]);
		ft_putendl_fd("pa", 1);
		refs[1][1]++;
		ft_free(min, mvts, NULL, NULL);
	}
}
