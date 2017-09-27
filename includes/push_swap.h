/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:06:40 by anazar            #+#    #+#             */
/*   Updated: 2017/09/05 11:51:34 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

void				push_swap(int ar, char **arv);
int					find_min(t_stack *a, int *before, int *after);
int					find_max(t_stack *a, int *before, int *after);
int					last(t_stack *a);
int					rev_sorted(t_stack *a);
int					is_max(t_stack *a, int value);

void				operate(t_stack **a, t_stack **b);
void				optimize_move(t_stack **a, t_stack **b);
void				brute_force(t_stack **a, t_stack **b);
void				op_push_a(t_stack **a, t_stack **b);
void				op_push_b(t_stack **a, t_stack **b);
void				op_swap_a(t_stack **a);
void				op_swap_b(t_stack **a);
void				op_swap_s(t_stack **a, t_stack **b);
void				op_rotate_a(t_stack **a);
void				op_rotate_b(t_stack **a);
void				op_rotate_r(t_stack **a, t_stack **b);
void				op_r_rotate_a(t_stack **a);
void				op_r_rotate_b(t_stack **a);
void				op_r_rotate_r(t_stack **a, t_stack **b);
void				op_double_r(t_stack **a, t_stack **b, int ra, int rb);
void				op_double_rr(t_stack **a, t_stack **b, int ra, int rb);
void				op_ra_rrb(t_stack **a, t_stack **b, int ra, int rb);
void				op_rra_rb(t_stack **a, t_stack **b, int ra, int rb);

#endif
