/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
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
	int		*a;
	int		*b;
	int		*lens;
	int		**refs;

	lens = (int *)malloc(sizeof(int) * 2);
	if (!lens)
		return (0);
	lens[0] = ac - 1;
	lens[1] = 0;
	a = ft_args_check(ac, av);
	ft_exit(a, lens, 0, NULL);
	b = (int *)malloc(sizeof(int));
	ft_exit(b, a, lens, NULL);
	refs = (int **)malloc(sizeof(int *));
	if (!refs)
	{
		free(lens);
		ft_exit(NULL, b, 0, NULL);
	}
	refs[0] = ft_ref(ac, a, refs);
	ft_gnl(&a, &b, refs, lens);
	ft_checker(a, b, refs, lens);
	free(a);
	return (0);
}
