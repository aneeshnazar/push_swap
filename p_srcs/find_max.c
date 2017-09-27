/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:40:56 by anazar            #+#    #+#             */
/*   Updated: 2017/08/25 17:41:45 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					find_max(t_stack *a, int *before, int *after)
{
	int				max;
	int				num;
	int				len;

	max = a->value;
	num = 0;
	len = 0;
	while (a)
	{
		if (a->value > max)
		{
			max = a->value;
			num = len;
		}
		++len;
		a = a->last;
	}
	*before = num;
	*after = len - num;
	return (max);
}
