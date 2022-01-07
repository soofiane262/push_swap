/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:01 by sel-mars          #+#    #+#             */
/*   Updated: 2021/12/29 15:29:19 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

void	ft_final_rotate(int **a, int **refs);
void	ft_rotates(int **a, int **b, char **rotates_a, char **rotates_b, int alen, int blen);
void	ft_sort(int full_len, int **a, int **b, int **ref);
int		*ft_sort_ext00(int *i, int full_len, int **refs, int *mvts);
char	**ft_sort_ext01(int full_len, int **refs, int **min);
void	ft_sort_ext02(int *i, int *start, int **a, int **refs);
void	ft_sort_ext03(int *i, int *start, int **a, int **b);
char	**ft_sort_ext04(int j, int **min);
int		*ft_count_mvts(int full_len, int *a, int *b, int **refs);
void	ft_count_mvts_ext00(int *i, int **refs, int *a, int *start);
void	ft_count_mvts_ext01(int *i, int *a, int b_j, int start);
void	ft_count_mvts_ext02(int *i, int **refs, int *temp);
void	ft_count_mvts_ext03(int *i, int **refs, int full_len, int *temp);
int		*ft_make_b(int ac, int **a);
void	ft_rotate_before_push(int *i, int *len, int **a, int *refa);
int		ft_check_dup(int *a, int i);
int		*ft_args_check(int ac, char **av);
void	ft_swap(int *ref_i, int *ref_j);
int		*ft_ref(int ac, int *a);
int		*ft_refa(int *a, int full_len);
int		*ft_refa_ext(int i, int *a, int full_len, int *tempi);
int		*ft_sorted_refa(int *refa_len, int full_len, int *a);
int		*ft_intdup(int *x, int len);
void	ft_exit(int *x, int *y, int *z, int *t);
void	ft_p(int **x, int **y, int xlen, int ylen);
void	ft_s(int *x, char *c);
void	ft_r_all(int *a, int *b, int alen, int blen);
void	ft_rr_all(int *a, int *b, int alen, int blen);
void	ft_r(int *x, int xlen, char *c);
void	ft_rr(int *x, int xlen, char *c);
void	ft_free(int *x, int *y, char **z, char **t);



void	ft_putnbrs(int len, int *x);

#endif