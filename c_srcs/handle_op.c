/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:34:19 by anazar            #+#    #+#             */
/*   Updated: 2017/08/24 23:27:21 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	handle_swap(t_stack **a, t_stack **b, char *buf)
{
	if (!ft_strcmp(buf, "sa"))
		swap(a);
	if (!ft_strcmp(buf, "sb"))
		swap(b);
	if (!ft_strcmp(buf, "ss"))
	{
		swap(a);
		swap(b);
	}
}

void	handle_rotate(t_stack **a, t_stack **b, char *buf)
{
	if (!ft_strcmp(buf, "ra"))
		rotate(a);
	if (!ft_strcmp(buf, "rb"))
		rotate(b);
	if (!ft_strcmp(buf, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strcmp(buf, "rra"))
		r_rotate(a);
	if (!ft_strcmp(buf, "rrb"))
		r_rotate(b);
	if (!ft_strcmp(buf, "rrr"))
	{
		r_rotate(a);
		r_rotate(b);
	}
}

void	handle_push(t_stack **a, t_stack **b, char *buf)
{
	if (!ft_strcmp(buf, "pa"))
		push_from_stack(a, b);
	if (!ft_strcmp(buf, "pb"))
		push_from_stack(b, a);
}

void	handle_op(t_stack **a, t_stack **b, char *buf)
{
	handle_push(a, b, buf);
	handle_swap(a, b, buf);
	handle_rotate(a, b, buf);
}
