/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_double_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:11:42 by anazar            #+#    #+#             */
/*   Updated: 2017/09/03 20:37:29 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_single_rot(t_stack **a, t_stack **b, int rra, int rrb)
{
	while (rra || rrb)
	{
		if (rra)
		{
			op_r_rotate_a(a);
			--rra;
		}
		else
		{
			op_r_rotate_b(b);
			--rrb;
		}
	}
}

void		op_double_rr(t_stack **a, t_stack **b, int rra, int rrb)
{
	while (rra && rrb)
	{
		op_r_rotate_r(a, b);
		--rra;
		--rrb;
	}
	handle_single_rot(a, b, rra, rrb);
	op_push_b(b, a);
}
