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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int		ft_check_dup(int *a, int i);
int		*ft_args_check(int ac, char **av);
void	ft_swap(int *ref_i, int *ref_j, int temp);
int		*ft_refa(int ac, int *ref);
int		*ft_refb(int ac, int *ref);
void	ft_exit(int *x, int *y, int *z);
#endif