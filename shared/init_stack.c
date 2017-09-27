/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:02:06 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 21:44:14 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static int	not_in(t_stack *top, int num)
{
	while (top)
	{
		if (top->value == num)
			return (0);
		top = top->last;
	}
	return (1);
}

t_stack		*init_stack(int argc, char **argv)
{
	t_stack	*top;
	int		num;

	top = NULL;
	while (argc >= 0)
	{
		num = ft_atoi(argv[argc]);
		if (not_in(top, num))
			push(&top, num);
		else
			error(&top, NULL);
		--argc;
	}
	return (top);
}
