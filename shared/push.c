/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:12:32 by anazar            #+#    #+#             */
/*   Updated: 2017/09/03 20:38:21 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void		push(t_stack **top, int num)
{
	t_stack	*n;

	n = (t_stack *)ft_memalloc(sizeof(t_stack));
	n->value = num;
	n->last = *top;
	*top = n;
}
