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
	refs[1] = ft_refa(a, ac - 1);
	ft_check_sort(a, refs, ac - 1);
	b = ft_make_b(ac - 1, &a, refs);
	ft_sort(ac - 1, &a, &b, refs);
	ft_final_rotate(&a, refs);
	ft_free(a, b, NULL, NULL);
	ft_free(refs[0], refs[1], NULL, NULL);
	free(refs);
	return (0);
}
