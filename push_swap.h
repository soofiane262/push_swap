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
# include "gnl/get_next_line.h"

void	ft_check_sort(int **a, int **refs, int full_len);
void	ft_check_sort_ext(int **a, int i, int *start, int full_len);
void	ft_little_sort(int **a, int full_len, int **refs);
void	ft_final_rotate(int **a, int **refs);
void	ft_rotates(int **a, int **b, int *rotates, int *lens);
void	ft_sort(int full_len, int **a, int **b, int **ref);
int		*ft_sort_ext00(int *i, int full_len, int **refs, int *mvts);
int		ft_sort_ext01(int full_len, int **refs, int **min);
void	ft_sort_ext02(int *i, int *start, int **a, int **refs);
void	ft_sort_ext03(int *i, int *start, int **a, int b_min);
int		ft_sort_ext04(int *ii, int *j, int **min, int **refs);
int		*ft_join_rotates(int rotates_a, int rotates_b);
void	ft_join_lens(int **min, int alen, int blen);
int		*ft_count_mvts(int full_len, int *a, int *b, int **refs);
void	ft_count_mvts_ext00(int *i, int **refs, int *a, int *start);
void	ft_count_mvts_ext01(int *i, int *a, int b_j, int start);
void	ft_count_mvts_ext02(int *i, int **refs, int *temp);
void	ft_count_mvts_ext03(int *i, int **refs, int full_len, int *temp);
int		*ft_make_b(int ac, int **a, int **refs);
void	ft_rotate_before_push(int *i, int *len, int **a, int *refa);
int		ft_check_dup(int *a, int i);
int		*ft_args_check(int ac, char **av);
void	ft_swap(int *ref_i, int *ref_j);
int		*ft_ref(int ac, int *a, int **refs);
int		*ft_refa(int *a, int full_len);
int		*ft_refa_ext00(int i, int *a, int full_len, int t);
void	ft_refa_ext01(int *x, int y, int *z, int t);
int		*ft_sorted_refa(int *refa_len, int **refs);
int		*ft_intdup(int *x, int len);
int		*ft_intdup2(int *x, int len);
int		*ft_refadup(int *x, int len);
void	ft_exit(int *x, int *y, int *z, int **t);
void	ft_s(int *x, char *c);
void	ft_p(int **x, int **y, int xlen, int ylen);
void	ft_r_all(int *a, int *b, int alen, int blen);
void	ft_rr_all(int *a, int *b, int alen, int blen);
void	ft_r(int *x, int xlen, char *c);
void	ft_rr(int *x, int xlen, char *c);
void	ft_free(int *x, int *y, char **z, char **t);
void	ft_free_arr(char **arr);
void	ft_init(int *i, int *j, int *k);
int		ft_check_digit(char *str);
void	ft_putnbrs(int len, int *x);
void	ft_checker(int *a, int *b, int **refs, int *lens);
void	ft_execute_inst(int **a, int **b, char *gnl, int **len);
void	ft_p_checker(int **x, int **y, int xlen, int ylen);
void	ft_s_checker(int *x);
void	ft_s_all_checker(int **x, int **y);
void	ft_r_checker(int *x, int xlen);
void	ft_r_all_checker(int **x, int **y, int xlen, int ylen);
void	ft_rr_checker(int *x, int xlen);
void	ft_rr_all_checker(int **x, int **y, int xlen, int ylen);
void	ft_gnl(int **a, int **b, int **refs, int *lens);
#endif