/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:48:12 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 22:24:45 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	char	**nums;
	int		len;

	if (argc == 1)
		return (0);
	else
		nums = ft_multi_strsplit(argc, argv, &len);
	if (!validate(len, nums))
		error(NULL, NULL);
	else
		checker(len, nums);
	free_str_list(len, nums);
	return (0);
}
