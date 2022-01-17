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

void	ft_sort_two(int **x, int full_len, char *c)
{
	if (full_len == 2 && (*x)[0] > (*x)[1])
		ft_s(*x, c);
}

void	ft_sort_three(int **x, int full_len, char *c)
{
	if (full_len == 3 && (*x)[0] > (*x)[1] && (*x)[0] > (*x)[2])
		ft_r(*x, full_len, c);
	if (full_len == 3 && (*x)[0] < (*x)[1] && (*x)[1] > (*x)[2])
		ft_rr(*x, full_len, c);
	if (full_len == 3 && (*x)[0] > (*x)[1] && (*x)[1] < (*x)[2])
		ft_s(*x, c);
}

void	ft_sort_five(int **a, int full_len, int mid)
{
	int	i;
	int	*b;

	b = (int *)malloc(sizeof(int));
	i = 0;
	while (i < 2)
	{
		if ((*a)[0] < mid)
		{
			ft_p(a, &b, full_len - i, i);
			ft_putendl_fd("pb", 1);
			i++;
		}
		ft_rr(*a, full_len - i, "a");
	}
	ft_sort_three(a, 3, "a");
	if (b[0] < b[1])
		ft_s(b, "b");
	ft_p(&b, a, 2, 3);
	ft_putendl_fd("pa", 1);
	ft_p(&b, a, 1, 4);
	ft_putendl_fd("pa", 1);
	free(b);
}

void	ft_little_sort(int **a, int full_len, int **refs)
{
	if (full_len == 2 || full_len == 3 || full_len == 5)
	{
		ft_sort_two(a, full_len, "a");
		ft_sort_three(a, full_len, "a");
		if (full_len == 5)
			ft_sort_five(a, full_len, refs[0][2]);
		ft_free(*a, refs[0], NULL, NULL);
		free(refs[1]);
		free(refs);
		exit(0);
	}
}

void	ft_new_sort(int full_len, int **a, int **b, int **refs)
{
	// int	i;
	// int	count;
	// int	temp[1000];
	// int	*idxs;

	// idxs = (int *)malloc(sizeof(int) * full_len - refs[1][1]);
	// count = 0;



ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);
ft_putstr_fd("a", 1);
ft_putnbrs(refs[1][1], *a);
ft_putstr_fd("b", 1);
ft_putnbrs(full_len - refs[1][1], *b);
ft_putstr_fd("---------------------------------------------------------\n\n", 1);
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
	if (ac == 2)
	{
		ft_free(a, refs[0], NULL, NULL);
		free(refs);
		exit(0);
	}
	refs[1] = ft_refa(a, ac - 1);




// ft_putstr_fd("---------------------------------------------------------\n\n", 1);
// ft_putstr_fd("a", 1);
// ft_putnbrs(ac - 1, a);
// ft_putstr_fd("ref", 1);
// ft_putnbrs(ac - 1, refs[0]);
// ft_putstr_fd("refa", 1);
// ft_putnbrs(refs[1][1] + 1, refs[1]);
// ft_putstr_fd("---------------------------------------------------------\n\n", 1);






	ft_check_sort(&a, refs, ac - 1);
	ft_little_sort(&a, ac - 1, refs);
	b = ft_make_b(ac - 1, &a, refs);





// ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);
// ft_putstr_fd("a", 1);
// ft_putnbrs(refs[1][1], a);
// ft_putstr_fd("b", 1);
// ft_putnbrs(ac - refs[1][1] - 1, b);
// ft_putstr_fd("---------------------------------------------------------\n\n", 1);




/////////////////////////////////////////////
	ft_sort(ac - 1, &a, &b, refs);
/////////////////////////////////////////////


/////////////////////////////////////////////
	// ft_new_sort(ac - 1, &a, &b, refs);
/////////////////////////////////////////////








	ft_final_rotate(&a, refs);




// ft_putstr_fd("\n---------------------------------------------------------\n\n", 1);
// ft_putstr_fd("sorted", 1);
// ft_putnbrs(ac - 1, a);
// ft_putstr_fd("---------------------------------------------------------\n\n", 1);




	ft_free(a, b, NULL, NULL);
	ft_free(refs[0], refs[1], NULL, NULL);
	free(refs);
	return (0);
}
