/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:22:07 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 21:52:27 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "libft.h"

typedef struct		s_stack
{
	int				value;
	int				nra;
	int				nrra;
	int				nrb;
	int				nrrb;
	int				dr_moves;
	int				drr_moves;
	int				ra_rrb_moves;
	int				rra_rb_moves;
	int				min_moves;
	struct s_stack	*last;
}					t_stack;

t_stack				*init_stack(int argc, char **argv);
int					validate(int argc, char **argv);
void				push(t_stack **curr, int n_val);
int					pop(t_stack **curr);
void				print(t_stack *curr);
void				print2(t_stack *a, t_stack *b);
int					check_sort(t_stack *a, t_stack *b);
int					is_sorted(t_stack *a);
void				swap(t_stack **a);
void				rotate(t_stack **a);
void				r_rotate(t_stack **a);
void				push_from_stack(t_stack **a, t_stack **b);
void				error(t_stack **a, t_stack **b);
char				**ft_multi_strsplit(int argc, char **str, int *len);
int					get_list_len(t_stack *a);
int					in_stack(t_stack *a, int value);
void				free_stack(t_stack **top);
void				free_str_list(int argc, char **argv);

#endif
