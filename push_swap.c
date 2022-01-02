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
	int	blen;
	int	*b;
	int	*ref;
	int	*refb;

	ref = ft_ref(full_len, *a);
	refb = ft_refb(--full_len, ref, *a);
	blen = ft_len(full_len, 'b');
	b = (int *)malloc(sizeof(int) * blen);
	ft_exit(b, *a, ref, refb);
	i = 0;
	while (i < blen)
	{
		if ((*a)[0] > (*a)[1])
			ft_s(*a, "a");
		if ((*a)[0] <= refb[0])
		{
			ft_pb(a, b, i, full_len - i);
			ft_check_for_sb(b, i++);
	ft_putstr_fd("---------------------------------------------------------\n\n", 1);
	ft_putstr_fd("i	", 1);
	ft_putnbr_fd(i, 1);
	ft_putstr_fd("\n\n", 1);
	ft_putchar_fd('a', 1);
	ft_putnbrs(ft_len(full_len, 'a'), *a);
	ft_putchar_fd('b', 1);
	ft_putnbrs(ft_len(full_len, 'b'), b);
	ft_putstr_fd("---------------------------------------------------------\n", 1);
		}
		else
			ft_r(*a, full_len - i, "a");
	}
	return (b);
}

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

void	ft_sort(int full_len, int **a, int **b, int *ref)
{
	(void)full_len;
	(void)a;
	(void)b;
	(void)ref;
}

int	main(int ac, char **av)
{
	int	*a;
	// int	*b;
	int	*ref;

	a = ft_args_check(ac, av);
	ref = ft_ref(ac, a);
	ft_putstr_fd("---------------------------------------------------------\n\n", 1);
	ft_putstr_fd("a", 1);
	ft_putnbrs(ac - 1, a);
	ft_putstr_fd("ref", 1);
	ft_putnbrs(ac - 1, ref);
	ft_putstr_fd("refa", 1);
	ft_putnbrs(ft_len(ac - 1, 'a'), ft_refa(ac, ref, a));
	ft_putstr_fd("---------------------------------------------------------\n\n", 1);
	// b = ft_make_b(ac, &a);
	// ft_sort(ac - 1, &a, &b, ref);
	ft_putstr_fd("sorted", 1);
	ft_putnbrs(ac - 1, a);
	ft_putstr_fd("---------------------------------------------------------\n", 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
