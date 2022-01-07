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

void	ft_sort(int full_len, int **a, int **b, int **refs)
{
	int	i[3];
	int	*min;
	int	*mvts;

	while (refs[1][1] != full_len)
	{
		i[0] = 0;
		mvts = ft_count_mvts(full_len, *a, *b, refs);
		min = ft_sort_ext00(&i[0], full_len, refs, mvts);
		ft_sort_ext01(b, full_len, refs, &min);
		i[0] = 0;
		i[1] = 0;
		i[2] = 0;
		ft_sort_ext02(&i[0], &i[2], a, refs);
		while (i[0] < refs[1][1] && (*a)[i[0]] < (*b)[0])
			i[0]++;
		ft_sort_ext03(&i[0], &i[2], a, b);
		while (i[0] != refs[1][1] && i[0] <= refs[1][1] / 2 && i[0]--)
			i[1]++;
		ft_sort_ext04(i[1], &min, a, refs);
		ft_p(b, a, full_len - refs[1][1], refs[1][1]);
		ft_putendl_fd("pa", 1);
		ft_free(min, mvts);
		refs[1][1]++;
	}
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	**refs;

	a = ft_args_check(ac, av);
	refs = (int **)malloc(sizeof(int *) * 2);
	refs[0] = ft_ref(ac, a);
	refs[1] = ft_refa(a, ac - 1);
	b = ft_make_b(ac - 1, &a);
	ft_sort(ac - 1, &a, &b, refs);
	ft_final_rotate(&a, refs);
	return (0);
}
