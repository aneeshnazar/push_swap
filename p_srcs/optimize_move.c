/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:41:48 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 17:38:02 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NRA tmp_a->nra
#define NRRA tmp_a->nrra
#define NRB tmp_a->nrb
#define NRRB tmp_a->nrrb
#define DRM tmp_a->dr_moves
#define DRRM tmp_a->drr_moves
#define RARRB tmp_a->ra_rrb_moves
#define RRARB tmp_a->rra_rb_moves
#include "push_swap.h"

static void	find_val(int value, int *before, int *after, t_stack *a)
{
	int	i;
	int	len;

	i = 0;
	len = get_list_len(a);
	while (a)
	{
		if (a->value == value)
			break ;
		++i;
		a = a->last;
	}
	*before = i;
	*after = len - i;
}

static void	find_min_val(int value, int *before, int *after, t_stack *a)
{
	int		max;

	if (!a || !a->last || (value < last(a) && value > a->value))
	{
		*before = 0;
		*after = get_list_len(a);
	}
	else if (value < find_min(a, before, after) ||
			value > find_max(a, before, after))
	{
		max = find_max(a, before, after);
		return ;
	}
	else
	{
		while (!in_stack(a, value))
		{
			--value;
		}
		find_val(value, before, after, a);
	}
}

void		handle_optimal_move(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*tmp_a;

	tmp_a = *a;
	min = *a;
	while (tmp_a)
	{
		if (tmp_a->min_moves < min->min_moves)
			min = tmp_a;
		tmp_a = tmp_a->last;
	}
	if (min->min_moves == min->dr_moves)
		op_double_r(a, b, min->nra, min->nrb);
	else if (min->min_moves == min->drr_moves)
		op_double_rr(a, b, min->nrra, min->nrrb);
	else if (min->min_moves == min->rra_rb_moves)
		op_rra_rb(a, b, min->nrra, min->nrb);
	else if (min->min_moves == min->ra_rrb_moves)
		op_ra_rrb(a, b, min->nra, min->nrrb);
}

void		optimize_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	int		before;
	int		after;

	tmp_a = *a;
	while (tmp_a)
	{
		find_val(tmp_a->value, &before, &after, *a);
		tmp_a->nra = before;
		tmp_a->nrra = after;
		find_min_val(tmp_a->value, &before, &after, *b);
		tmp_a->nrb = before;
		tmp_a->nrrb = after;
		tmp_a->dr_moves = ft_max(NRA, NRB);
		tmp_a->drr_moves = ft_max(NRRA, NRRB);
		tmp_a->ra_rrb_moves = NRA + NRRB;
		tmp_a->rra_rb_moves = NRRA + NRB;
		tmp_a->min_moves = ft_min(ft_min(DRM, DRRM), ft_min(RARRB, RRARB));
		tmp_a = tmp_a->last;
	}
	handle_optimal_move(a, b);
}
