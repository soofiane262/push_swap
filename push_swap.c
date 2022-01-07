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

void	ft_rotates(int **a, int **b, char **rotates_a, char **rotates_b, int alen, int blen)
{
	int	i[2];


ft_putendl_fd("****************************", 1);
i[0] = 0;
while (rotates_a[i[0]])
	ft_putendl_fd(rotates_a[i[0]++], 1);
i[0] = 0;
while (rotates_b[i[0]])
	ft_putendl_fd(rotates_b[i[0]++], 1);
ft_putendl_fd("****************************", 1);




	i[0] = 0;
	while (rotates_a[i[0]] && rotates_b[i[0]] && !ft_strncmp(rotates_a[i[0]], "ra", 3) && !ft_strncmp(rotates_b[i[0]], "rb", 3))
	{
		ft_r_all(*a, *b, alen, blen);
		i[0]++;
	}
	while (rotates_a[i[0]] && rotates_b[i[0]] && !ft_strncmp(rotates_a[i[0]], "rra", 4) && !ft_strncmp(rotates_b[i[0]], "rrb", 4))
	{
		ft_rr_all(*a, *b, alen, blen);
		i[0]++;
	}
	i[1] = i[0];
	while (rotates_a[i[0]] && !ft_strncmp(rotates_a[i[0]], "ra", 3))
	{
		ft_r(*a, alen, "a");
		i[0]++;
	}
	while (rotates_b[i[1]] && !ft_strncmp(rotates_b[i[1]], "rb", 3))
	{
		ft_r(*b, blen, "b");
		i[1]++;
	}
	while (rotates_a[i[0]] && !ft_strncmp(rotates_a[i[0]], "rra", 4))
	{
		ft_rr(*a, alen, "a");
		i[0]++;
	}
	while (rotates_b[i[1]] && !ft_strncmp(rotates_b[i[1]], "rrb", 4))
	{
		ft_rr(*b, blen, "b");
		i[1]++;
	}
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





ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);
ft_putstr_fd("a", 1);
ft_putnbrs(refs[1][1], *a);
ft_putstr_fd("b", 1);
ft_putnbrs(full_len - refs[1][1], *b);
ft_putstr_fd("mvts", 1);
ft_putnbrs(full_len - refs[1][1], mvts);
ft_putstr_fd("---------------------------------------------------------\n\n", 1);





		min = ft_sort_ext00(&i[0], full_len, refs, mvts);
		rotates_b = ft_sort_ext01(full_len, refs, &min);
		i[0] = 0;
		i[1] = 0;
		i[2] = 0;
		ft_sort_ext02(&i[0], &i[2], a, refs);
		while (i[0] < refs[1][1] && (*a)[i[0]] < (*b)[0])
			i[0]++;
		ft_sort_ext03(&i[0], &i[2], a, b);
		while (i[0] != refs[1][1] && i[0] <= refs[1][1] / 2 && i[0]--)
			i[1]++;
		rotates_a = ft_sort_ext04(i[1], &min);
		ft_rotates(a, b, rotates_a, rotates_b, refs[1][1], full_len - refs[1][1]);
		ft_p(b, a, full_len - refs[1][1], refs[1][1]);
		ft_putendl_fd("pa", 1);
		refs[1][1]++;








		ft_free(min, mvts, rotates_a, rotates_b);



	}
}





void	ft_putnbrs(int len, int *x)
{
	int	i;

	ft_putstr_fd("	. :", 1);
	i = 0;
	while (i < len)
	{
		ft_putstr_fd(" | ", 1);
		ft_putnbr_fd(x[i++], 1);
	}
	ft_putstr_fd(" | : .\n\n", 1);
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



ft_putstr_fd("---------------------------------------------------------\n\n", 1);
ft_putstr_fd("a", 1);
ft_putnbrs(ac - 1, a);
ft_putstr_fd("ref", 1);
ft_putnbrs(ac - 1, refs[0]);
ft_putstr_fd("refa", 1);
ft_putnbrs(refs[1][1] + 1, refs[1]);
ft_putstr_fd("---------------------------------------------------------\n\n", 1);





	b = ft_make_b(ac - 1, &a);



ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);
ft_putstr_fd("a", 1);
ft_putnbrs(refs[1][1], a);
ft_putstr_fd("b", 1);
ft_putnbrs(ac - refs[1][1] - 1, b);
ft_putstr_fd("---------------------------------------------------------\n\n", 1);





	ft_sort(ac - 1, &a, &b, refs);
	ft_final_rotate(&a, refs);

ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);
ft_putstr_fd("sorted", 1);
ft_putnbrs(ac - 1, a);
ft_putstr_fd("---------------------------------------------------------\n\n", 1);

	return (0);
}
