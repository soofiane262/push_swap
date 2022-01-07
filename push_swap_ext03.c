/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ext03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int *x, int *y, int *z, int *t)
{
	if (!x)
	{
		if (y)
			free(y);
		if (z)
			free(z);
		if (t)
			free(t);
		exit(1);
	}	
}

int	ft_check_dup(int *a, int i)
{
	int	j;

	j = i--;
	while (i >= 0)
	{
		if (a[j] == a[i])
			return (-1);
		i--;
	}
	return (0);
}

int	*ft_args_check(int ac, char **av)
{
	int			i;
	int			*a;
	long long	ret;

	a = (int *)malloc(sizeof(int) * (ac - 1));
	ft_exit(a, NULL, NULL, NULL);
	i = 0;
	while (++i < ac)
	{
		ret = ft_atoi(av[i]);
		a[i - 1] = ret;
		if (ft_check_dup(a, i - 1))
		{
			ft_putstr_fd("Error\n", 2);
			ft_exit(a, NULL, NULL, NULL);
		}
	}
	return (a);
}
