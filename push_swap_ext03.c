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

void	ft_pb(int **a, int *b, int l, int full_len)
{
	int	*temp;

	while (l >= 0)
	{
		*(b + l + 1) = *(b + l);
		l--;
	}
	*b = (*a)[0];
	temp = ft_intdup(*a + 1, full_len - 1);
	free(*a);
	*a = temp;
	ft_putendl_fd("pb", 1);
}

void	ft_pa(int **a, int *b, int full_len)
{
	int	i;
	int	j;
	int	alen;
	int	blen;
	int	*temp;

	alen = ft_len(full_len, 'a');
	blen = ft_len(full_len, 'b');
	temp = (int *)malloc(sizeof(int) * alen);
	ft_exit(temp, *a, b, 0);
	i = 0;
	while (blen)
	{
		temp[i++] = b[--blen];
		ft_putendl_fd("pa", 1);
	}
	j = 0;
	while (j < alen)
		temp[i++] = (*a)[j++];
	free(*a);
	*a = temp;
}

void	ft_s(int *x, char *c)
{
	int	temp;

	temp = *x;
	*x = *(x + 1);
	*(x + 1) = temp;
	ft_putendl_fd(ft_strjoin("s", c), 1);
}

void	ft_r(int *x, int xlen, char *c)
{
	int	i;
	int	temp;

	temp = x[0];
	i = 0;
	while (i < xlen - 1)
	{
		*(x + i) = *(x + i + 1);
		i++;
	}
	*(x + i) = temp;
	ft_putendl_fd(ft_strjoin("r", c), 1);
}

void	ft_check_for_sb(int *b, int i)
{
	if (i && b[0] < b[1])
	{
		ft_s(b, "b");
	}
}