/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 21:37:47 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 21:47:02 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	free_stack(t_stack **top)
{
	while (*top)
		pop(top);
	*top = NULL;
}
