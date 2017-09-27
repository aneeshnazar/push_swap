/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra_rb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 19:33:41 by anazar            #+#    #+#             */
/*   Updated: 2017/09/03 20:34:54 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra_rb(t_stack **a, t_stack **b, int rra, int rb)
{
	while (rra)
	{
		op_r_rotate_a(a);
		--rra;
	}
	while (rb)
	{
		op_rotate_b(b);
		--rb;
	}
	op_push_b(b, a);
}
