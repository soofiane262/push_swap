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


// int	ft_check_sort_a(int full_len, int **a, int *ref)
// {
// 	int	i;
// 	int	j;
// 	int	*refa;

// 	refa = ft_refa(full_len, ref, *a);
// 	i = 0;
// 	while ((*a)[i] != refa[0])
// 		i++;
// 	j = 0;
// 	while (j < ft_len(full_len, 'a') - 1)
// 	{
// 		if ((*a)[i] != refa[j])
// 			return (0);
// 		if (i == ft_len(full_len, 'a') - 1)
// 			i = 0;
// 		else
// 			i++;
// 		j++;
// 	}
// 	while ((*a)[0] != refa[0])
// 		ft_r(*a, ft_len(full_len, 'a'), "a");
// 	return (1);
// }

// int	ft_check_sort_b(int full_len, int **b, int *ref)
// {
// 	int	i;
// 	int	j;
// 	int	*refb;

// 	refb = ft_refb(full_len, ref, *b);
// 	i = 0;
// 	while ((*b)[i] != refb[0])
// 		i++;
// 	j = 0;
// 	while (j < ft_len(full_len, 'b') - 1)
// 	{
// 		if ((*b)[i] != refb[j])
// 			return (0);
// 		if (i == ft_len(full_len, 'b') - 1)
// 			i = 0;
// 		else
// 			i++;
// 		j++;
// 	}
// 	while ((*b)[0] != refb[0])
// 		ft_r(*b, ft_len(full_len, 'b'), "b");
// 	return (1);
// }

// void	ft_sort(int full_len, int **a, int **b, int *ref)
// {
// 	int	i = 0;
// 	// while (!ft_check_sort_a(full_len, a, ref)
// 	// 	|| !ft_check_sort_b(full_len, b, ref))
// 	while (i < 10)
// 	{
// 		ft_putstr_fd("---------------------------------------------------------\n\n", 1);
// 		ft_putstr_fd("i	", 1);
// 		ft_putnbr_fd(i, 1);
// 		ft_putstr_fd("\n\n", 1);
// 		ft_putchar_fd('a', 1);
// 		ft_putnbrs(ft_len(full_len, 'a'), *a);
// 		ft_putchar_fd('b', 1);
// 		ft_putnbrs(ft_len(full_len, 'b'), *b);
// 		ft_putstr_fd("---------------------------------------------------------\n", 1);
// 		if ((*a)[0] > (*a)[1])
// 			ft_s(*a, "a");
// 		if ((*b)[0] < (*b)[1])
// 			ft_s(*b, "b");
// 		if (!ft_check_sort_a(full_len, a, ref))
// 			ft_r(*a, ft_len(full_len, 'a'), "a");
// 		if (!ft_check_sort_b(full_len, b, ref))
// 			ft_r(*b, ft_len(full_len, 'b'), "b");
// 		i++;
// 	}
// 	ft_putstr_fd("---------------------------------------------------------\n\n", 1);
// 	ft_putchar_fd('a', 1);
// 	ft_putnbrs(ft_len(full_len, 'a'), *a);
// 	ft_putchar_fd('b', 1);
// 	ft_putnbrs(ft_len(full_len, 'b'), *b);
// 	ft_putstr_fd("---------------------------------------------------------\n", 1);
// 	ft_pa(a, *b, full_len);
// }

int	*ft_make_b(int full_len, int **a)
{
	int	i;
	int	alen;
	int	*b;
	int	*ref;
	int	*refa;

	ref = ft_ref(full_len--, *a);
	refa = ft_refa(ref, *a, full_len);
	alen = refa[1];
	b = (int *)malloc(sizeof(int));
	i = 0;
	while (i < refa[0])
	{
		ft_p(a, &b, full_len - i, i);
		ft_putendl_fd("pb", 1);
		i++;
	}
	while (alen)
	{
		ft_r(*a, full_len - i, "a");
		alen--;
	}
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
	// while (full_len - refs[1][1])
	// {
		if ((*b)[0] == refs[0][0])
		{
			ft_p(b, a, full_len - refs[1][1], refs[1][1]);
			ft_putendl_fd("pb", 1);
			refs[1][1]++;
		}
		if ((*b)[0] == refs[0][full_len - 1])
		{
			ft_p(b, a, full_len - refs[1][1], refs[1][1]);
			ft_putendl_fd("pb", 1);
			refs[1][1]++;
			ft_r(*a, refs[1][1], "a");
		}
	// 	while ((*b)[0] != refs[0][i])
	// }
}

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	**refs;

	a = ft_args_check(ac, av);
	refs = (int **)malloc(sizeof(int *) * 2);
	refs[0] = ft_ref(ac, a);
	refs[1] = ft_refa(refs[0], a, ac - 1);


	ft_putstr_fd("---------------------------------------------------------\n\n", 1);
	ft_putstr_fd("a", 1);
	ft_putnbrs(ac - 1, a);
	ft_putstr_fd("ref", 1);
	ft_putnbrs(ac - 1, refs[0]);
	ft_putstr_fd("refa", 1);
	ft_putnbrs(2, refs[1]);
	ft_putstr_fd("---------------------------------------------------------\n\n", 1);




	b = ft_make_b(ac, &a);


	ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);

	ft_putstr_fd("a", 1);
	ft_putnbrs(3, a);
	ft_putstr_fd("b", 1);
	ft_putnbrs(4, b);

	ft_putstr_fd("---------------------------------------------------------\n\n", 1);

	ft_sort(ac - 1, &a, &b, refs);



	ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);

	// ft_putstr_fd("sorted", 1);
	// ft_putnbrs(ac - 1, a);
	ft_putstr_fd("---------------------------------------------------------\n", 1);
	ft_putstr_fd("\n", 1);



	return (0);
}
