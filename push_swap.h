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

void	ft_sort(int full_len, int **a, int **b, int *ref);
int		*ft_make_b(int ac, int **a);
int		ft_check_dup(int *a, int i);
int		*ft_args_check(int ac, char **av);
void	ft_swap(int *ref_i, int *ref_j, int temp);
int		*ft_ref(int ac, int *a);
int		*ft_refa(int ac, int *ref, int *a);
int		*ft_refb(int ac, int *ref, int *a);
int		*ft_intdup(int *x, int len);
void	ft_putnbrs(int ac, int *x);
void	ft_exit(int *x, int *y, int *z, int *t);
void	ft_pa(int **a, int *b, int full_len);
void	ft_pb(int **a, int *b, int l, int full_len);
void	ft_s(int *x, char *c);
void	ft_r(int *x, int xlen, char *c);
void	ft_check_for_sb(int *b, int i);
int		ft_len(int x, char c);
#endif