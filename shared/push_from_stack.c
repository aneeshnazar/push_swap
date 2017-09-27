/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:17:56 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 14:39:00 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_from_stack(t_stack **dest, t_stack **src)
{
	int	tmp;

	if (!*src)
		return ;
	tmp = pop(src);
	push(dest, tmp);
}
