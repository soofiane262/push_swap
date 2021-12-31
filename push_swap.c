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

int	*ft_ref(int ac, int *a)
{
	int	i;
	int	j;
	int	*ref;

	ref = (int *)malloc(sizeof(int) * (ac - 1));
	if (!ref)
		return (NULL);
	i = 0;
	while (i < ac - 1)
	{
		ref[i] = a[i];
		i++;
	}
	i = 0;
	while (i < ac - 2)
	{
		j = i;
		while (++j < ac - 1)
			if (ref[i] > ref[j])
				ft_swap(ref + i, ref + j, ref[i]);
		i++;
	}
	return (ref);
}

int	main(int ac, char **av)
{
	int	i;
	int	*a;
	int	*b;
	int	*ref;
	int	*refa;
	int	*refb;

	a = ft_args_check(ac, av);
	ft_exit(a, NULL, NULL);
	ref = ft_ref(ac, a);
	ft_exit(ref, a, NULL);
	refa = ft_refa(ac - 1, ref);
	refb = ft_refb(ac - 1, ref);
	i = 0;
	while (i <= 2)
		ft_putnbr_fd(refa[i++], 1);
	i = 0;
	while (i < 2)
		ft_putnbr_fd(refb[i++], 1);
	return (0);
}
