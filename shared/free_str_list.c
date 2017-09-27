/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 21:51:30 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 22:26:20 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_str_list(int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		ft_strdel(&argv[i]);
		++i;
	}
	free(argv);
}
