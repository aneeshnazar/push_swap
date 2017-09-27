/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:13:06 by anazar            #+#    #+#             */
/*   Updated: 2017/09/05 14:25:24 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*tmp;
	t_stack	*curr;

	if (*a && (*a)->last)
	{
		first = (t_stack *)ft_memalloc(sizeof(t_stack));
		first->value = pop(a);
		first->last = NULL;
		tmp = *a;
		curr = tmp;
		while (curr->last)
			curr = curr->last;
		curr->last = first;
		*a = tmp;
	}
}
