/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:47:13 by anazar            #+#    #+#             */
/*   Updated: 2017/09/09 17:17:35 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		push_swap(len, nums);
	free_str_list(len, nums);
	return (0);
}
