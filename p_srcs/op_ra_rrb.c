/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra_rrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:38:17 by anazar            #+#    #+#             */
/*   Updated: 2017/09/03 20:34:41 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra_rrb(t_stack **a, t_stack **b, int ra, int rrb)
{
	while (ra)
	{
		op_rotate_a(a);
		--ra;
	}
	while (rrb)
	{
		op_r_rotate_b(b);
		--rrb;
	}
	op_push_b(b, a);
}
