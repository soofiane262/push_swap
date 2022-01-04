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

#include "libft/libft.h"
#include "push_swap.h"

int	*ft_make_b(int full_len, int **a)
{
	int	i;
	int	alen;
	int	*b;
	int	*ref;
	int	*refa;

	ref = ft_ref(full_len--, *a);
	refa = ft_refa(*a, full_len);
	alen = refa[1];
	b = (int *)malloc(sizeof(int));
	i = 0;
	while (i < refa[0])
	{
		ft_p(a, &b, full_len - i, i);
		ft_putendl_fd("pb", 1);
		i++;
	}
	// ft_putstr_fd("\ni\n", 1);
	// ft_putnbr_fd(i, 1);
	// if (alen / 2 < alen - refa[1])
		while (alen--)
			ft_r(*a, full_len - i, "a");
	// else if (alen / 2 > alen - refa[1])
	// 	while (alen-- != refa[1])
	// 		ft_rr(*a, full_len - i, "a");
	while (full_len - i != refa[1])
	{
		ft_p(a, &b, full_len - i, i);
		ft_putendl_fd("pb", 1);
		i++;
	}
	return (b);
}

void	ft_sort(int full_len, int **a, int **b, int **refs)
{
	int	i;
	int	start;

	while (refs[1][1] != full_len)
	{
		i = 0;
		start = 0;
		while (i + 1 < refs[1][1] && (*a)[i] < (*a)[i + 1])
			i++;
		if (i + 1 != refs[1][1] && (*a)[i] > (*a)[i + 1])
			start = i + 1;
		i = start;
		while (i < refs[1][1] && (*a)[i] < (*b)[0])
			i++;
		if (start && (*a)[0] < (*b)[0])
		{
			i = 0;
			while (i < start && (*a)[i] < (*b)[0])
				i++;
		}
		if (i != refs[1][1] && i <= refs[1][1] / 2)
			while (i--)
				ft_r(*a, refs[1][1], "a");
		else if (i != refs[1][1] && i > refs[1][1] / 2)
			while (i++ < refs[1][1])
				ft_rr(*a, refs[1][1], "a");
		// if (i != refs[1][1] && i > refs[1][1] / 2)
		// 	while (refs[1][1] - i > -1)
		// 	{
		// 		ft_rr(*a, refs[1][1], "a");
		// 		i++;
		// 	}
		ft_p(b, a, full_len - refs[1][1], refs[1][1]);
		refs[1][1]++;
		ft_putendl_fd("pa", 1);



	// ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);
	// ft_putstr_fd("a", 1);
	// ft_putnbrs(refs[1][1], *a);
	// ft_putstr_fd("b", 1);
	// ft_putnbrs(full_len - refs[1][1], *b);
	// ft_putstr_fd("---------------------------------------------------------\n\n", 1);

	}
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


int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	**refs;

	a = ft_args_check(ac, av);
	refs = (int **)malloc(sizeof(int *) * 2);
	refs[0] = ft_ref(ac, a);
	refs[1] = ft_refa(a, ac - 1);


	// ft_putstr_fd("---------------------------------------------------------\n\n", 1);
	// ft_putstr_fd("a", 1);
	// ft_putnbrs(ac - 1, a);
	// ft_putstr_fd("ref", 1);
	// ft_putnbrs(ac - 1, refs[0]);
	// ft_putstr_fd("refa", 1);
	// ft_putnbrs(2, refs[1]);
	// ft_putstr_fd("---------------------------------------------------------\n\n", 1);




	b = ft_make_b(ac, &a);


	// ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);

	// ft_putstr_fd("a", 1);
	// ft_putnbrs(refs[1][1], a);
	// ft_putstr_fd("b", 1);
	// ft_putnbrs(ac - refs[1][1] - 1, b);

	// ft_putstr_fd("---------------------------------------------------------\n\n", 1);

	ft_sort(ac - 1, &a, &b, refs);

	// ft_putstr_fd("a", 1);
	// ft_putnbrs(3, a);
	// ft_putstr_fd("b", 1);
	// ft_putnbrs(4, b);

	// ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);
	// ft_putstr_fd("sorted", 1);
	// ft_putnbrs(ac - 1, a);
	// ft_putstr_fd("---------------------------------------------------------\n", 1);
	// ft_putstr_fd("\n", 1);



	return (0);
}
