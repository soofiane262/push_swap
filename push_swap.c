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

#include "push_swap.h"

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

void	ft_rotates(int **a, int **b, char ***rotates, int *lens)
{
	int	i[2];

	ft_init(&i[0], &i[1], 0);
	while (rotates[0][i[0]] && rotates[1][i[1]]
			&& !ft_strncmp(rotates[0][i[0]], "ra", 3)
			&& !ft_strncmp(rotates[1][i[1]], "rb", 3))
		if (++i[0] && ++i[1])
			ft_r_all(*a, *b, lens[0], lens[1]);
	while (rotates[0][i[0]] && rotates[1][i[1]]
			&& !ft_strncmp(rotates[0][i[0]], "rra", 4)
			&& !ft_strncmp(rotates[1][i[1]], "rrb", 4))
		if (++i[0] && ++i[1])
			ft_rr_all(*a, *b, lens[0], lens[1]);
	while (rotates[0][i[0]] && !ft_strncmp(rotates[0][i[0]], "ra", 3))
		if (++i[0])
			ft_r(*a, lens[0], "a");
	while (rotates[0][i[0]] && !ft_strncmp(rotates[0][i[0]], "rra", 4))
		if (++i[0])
			ft_rr(*a, lens[0], "a");
	while (rotates[1][i[1]] && !ft_strncmp(rotates[1][i[1]], "rb", 3))
		if (++i[1])
			ft_r(*b, lens[1], "b");
	while (rotates[1][i[1]] && !ft_strncmp(rotates[1][i[1]], "rrb", 4))
		if (++i[1])
			ft_rr(*b, lens[1], "b");
	ft_free(NULL, NULL, rotates[0], rotates[1]);
	free(rotates);
}

void	ft_sort(int full_len, int **a, int **b, int **refs)
{
	int		i[3];
	int		*min;
	int		*mvts;
	char	**rotates_a;
	char	**rotates_b;

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
		ft_free(min, mvts, rotates_a, rotates_b);
	}
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	**refs;

	a = ft_args_check(ac, av);
	refs = (int **)malloc(sizeof(int *) * 2);
	if (!refs)
		ft_exit(NULL, NULL, NULL, refs);
	refs[0] = ft_ref(ac, a, refs);
	refs[1] = ft_refa(a, ac - 1, refs);
	b = ft_make_b(ac - 1, &a, refs);
	ft_sort(ac - 1, &a, &b, refs);
	ft_final_rotate(&a, refs);
	ft_free(a, b, NULL, NULL);
	ft_free(refs[0], refs[1], NULL, NULL);
	free(refs);	
	return (0);
}
