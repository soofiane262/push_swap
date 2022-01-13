/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ext01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker(int *a, int *b, int **refs, int *len)
{
	int	i;

	(void)b;
	i = 0;
	while (i < len[0] && a[i] == refs[0][i])
		i++;
	if (len[1] == 0 && i == len[0])
		ft_putendl_fd("OK", 1);
	else
	{
		ft_putendl_fd("KO", 1);
		free(b);
	}
	ft_free(refs[0], len, NULL, NULL);
	free(refs);
}

void	ft_r_all_checker(int **x, int **y, int xlen, int ylen)
{
	ft_r_checker(*x, xlen);
	ft_r_checker(*y, ylen);
}

void	ft_rr_all_checker(int **x, int **y, int xlen, int ylen)
{
	ft_rr_checker(*x, xlen);
	ft_rr_checker(*y, ylen);
}

void	ft_execute_inst(int **a, int **b, char *gnl, int **len)
{
	if (!ft_strncmp(gnl, "pa\n", 4))
		ft_p_checker(b, a, (*len)[1]--, (*len)[0]++);
	else if (!ft_strncmp(gnl, "pb\n", 4))
		ft_p_checker(a, b, (*len)[0]--, (*len)[1]++);
	else if (!ft_strncmp(gnl, "sa\n", 4))
		ft_s_checker(*a);
	else if (!ft_strncmp(gnl, "sb\n", 4))
		ft_s_checker(*b);
	else if (!ft_strncmp(gnl, "ss\n", 4))
		ft_s_all_checker(a, b);
	else if (!ft_strncmp(gnl, "ra\n", 4))
		ft_r_checker(*a, (*len)[0]);
	else if (!ft_strncmp(gnl, "rb\n", 4))
		ft_r_checker(*b, (*len)[1]);
	else if (!ft_strncmp(gnl, "rr\n", 4))
		ft_r_all_checker(a, b, (*len)[0], (*len)[1]);
	else if (!ft_strncmp(gnl, "rra\n", 5))
		ft_rr_checker(*a, (*len)[0]);
	else if (!ft_strncmp(gnl, "rrb\n", 5))
		ft_rr_checker(*b, (*len)[1]);
	else if (!ft_strncmp(gnl, "rrr\n", 5))
		ft_rr_all_checker(a, b, (*len)[0], (*len)[1]);
	else
		(*len)[0] = -1;
}

void	ft_gnl(int **a, int **b, int **refs, int *lens)
{
	char	*gnl;

	gnl = get_next_line(0);
	if (!gnl)
		return ;
	while (gnl)
	{
		ft_execute_inst(a, b, gnl, &lens);
		free(gnl);
		if (lens[0] == -1)
		{
			ft_free(*a, *b, NULL, NULL);
			ft_exit(NULL, lens, refs[0], refs);
		}
		gnl = get_next_line(0);
	}
}
