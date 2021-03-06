/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:40:05 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 22:06:33 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	error(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(0);
}
