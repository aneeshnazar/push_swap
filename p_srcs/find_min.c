/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:18:51 by anazar            #+#    #+#             */
/*   Updated: 2017/08/24 17:52:01 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					find_min(t_stack *a, int *before, int *after)
{
	int				min;
	int				num;
	int				len;

	min = a->value;
	num = 0;
	len = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			num = len;
		}
		++len;
		a = a->last;
	}
	*before = num;
	*after = len - num;
	return (min);
}
