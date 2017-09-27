/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_double_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:11:42 by anazar            #+#    #+#             */
/*   Updated: 2017/09/03 20:37:18 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_single_rot(t_stack **a, t_stack **b, int ra, int rb)
{
	while (ra || rb)
	{
		if (ra)
		{
			op_rotate_a(a);
			--ra;
		}
		else
		{
			op_rotate_b(b);
			--rb;
		}
	}
}

void		op_double_r(t_stack **a, t_stack **b, int ra, int rb)
{
	while (ra && rb)
	{
		op_rotate_r(a, b);
		--ra;
		--rb;
	}
	handle_single_rot(a, b, ra, rb);
	op_push_b(b, a);
}
