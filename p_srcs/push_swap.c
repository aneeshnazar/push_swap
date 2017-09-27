/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:36:43 by anazar            #+#    #+#             */
/*   Updated: 2017/09/05 19:55:49 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_sort(t_stack **b)
{
	int		rrb;
	int		rb;

	find_min(*b, &rb, &rrb);
	if (rb > rrb)
		while (!rev_sorted(*b))
			op_r_rotate_b(b);
	else
		while (!rev_sorted(*b))
			op_rotate_b(b);
}

void	zipper_merge(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (last(*a) < (*b)->value ||
				(is_max(*a, last(*a)) && ((*b)->value < (*a)->value)))
			op_push_a(a, b);
		else
			op_r_rotate_a(a);
	}
	while (!is_sorted(*a))
		op_rotate_a(a);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack(argc - 1, argv);
	b = NULL;
	if (!is_sorted(a))
	{
		if (get_list_len(a) < 8)
			brute_force(&a, &b);
		else
		{
			while (!is_sorted(a))
				optimize_move(&a, &b);
			if (b)
				rev_sort(&b);
			zipper_merge(&a, &b);
		}
	}
	free_stack(&a);
	free_stack(&b);
}
