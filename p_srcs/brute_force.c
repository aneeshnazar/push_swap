/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 23:16:17 by anazar            #+#    #+#             */
/*   Updated: 2017/09/05 19:56:03 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rot_rev_sorted(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->value;
	second = a->last->value;
	third = a->last->last->value;
	return ((first > second && second > third && third < first) ||
		(first > second && second < third && third > first) ||
		(first < second && second > third && third > first));
}

void	sort_three(t_stack **a)
{
	if (rot_rev_sorted(*a))
		op_swap_a(a);
	if (is_max(*a, (*a)->value))
		op_rotate_a(a);
	else if (!is_sorted(*a))
		op_r_rotate_a(a);
}

void	brute_force(t_stack **a, t_stack **b)
{
	int	before;
	int	after;

	if (get_list_len(*a) == 3)
	{
		sort_three(a);
		while (*b)
			op_push_a(a, b);
	}
	else if (get_list_len(*a) > 3)
	{
		find_min(*a, &before, &after);
		if (before < after)
			while (before-- > 0)
				op_rotate_a(a);
		else
			while (after-- > 0)
				op_r_rotate_a(a);
		op_push_b(b, a);
		brute_force(a, b);
	}
	else if ((*a)->last && (*a)->value > (*a)->last->value)
		op_swap_a(a);
}
