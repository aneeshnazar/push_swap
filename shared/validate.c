/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:49:46 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 22:10:29 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_numeric_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != '-' && str[i] != '+')
				return (0);
			else if (i != 0)
				return (0);
		}
		++i;
	}
	if (i > 11)
		return (0);
	else if (ft_atoll(str) > 2147483647 || ft_atoll(str) < -2147483648)
		return (0);
	return (1);
}

int			validate(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!is_numeric_str(argv[i]))
		{
			free_str_list(argc, argv);
			return (0);
		}
		++i;
	}
	return (1);
}
