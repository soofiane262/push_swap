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

int	*ft_refa(int ac, int *ref)
{
	int	i;
	int	var;
	int	*refa;

	var = ac / 2;
	if (var * 2 == ac)
		refa = (int *)malloc(sizeof(int) * var);
	else
		refa = (int *)malloc(sizeof(int) * (++var));
	if (!refa)
		return (NULL);
	i = 0;
	while (i < var)
	{
		refa[i] = ref[i];
		i++;
	}
	return (refa);
}

int	*ft_refb(int ac, int *ref)
{
	int	i;
	int	j;
	int	var;
	int	*refb;

	var = ac / 2;
	refb = (int *)malloc(sizeof(int) * var);
	if (!refb)
		return (NULL);
	if (var * 2 != ac)
		var++;
	i = 0;
	j = ac - 1;
	while (var < ac)
	{
		refb[i++] = ref[j--];
		var++;
	}
	return (refb);
}
