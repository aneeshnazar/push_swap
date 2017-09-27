/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:45:57 by anazar            #+#    #+#             */
/*   Updated: 2017/09/05 14:24:44 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	r_rotate(t_stack **a)
{
	t_stack	*curr;
	int		num;

	if (*a && (*a)->last)
	{
		curr = *a;
		while (curr->last)
			curr = curr->last;
		num = curr->value;
		push(a, num);
		curr = *a;
		while (curr->last->last)
			curr = curr->last;
		free(curr->last);
		curr->last = NULL;
	}
}
