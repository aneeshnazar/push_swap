/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_strsplit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 01:13:51 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 22:22:54 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static int	ft_strlistlen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		++i;
	return (i);
}

static char	**ft_strlistjoin(char **lst1, char **lst2)
{
	char	**new_list;
	size_t	lst1_len;
	size_t	lst2_len;
	size_t	i;
	size_t	j;

	lst1_len = lst1 == NULL ? 0 : ft_strlistlen(lst1);
	lst2_len = lst2 == NULL ? 0 : ft_strlistlen(lst2);
	i = 0;
	j = 0;
	new_list = (char **)ft_memalloc(sizeof(char *) * (lst1_len + lst2_len + 1));
	ft_bzero(new_list, lst1_len + lst2_len + 1);
	while (i < lst1_len)
	{
		new_list[i] = lst1[i];
		++i;
	}
	while (j < lst2_len)
	{
		new_list[i++] = lst2[j];
		++j;
	}
	return (new_list);
}

void		print_list(char **strs)
{
	while (*strs)
	{
		ft_putendl(*strs);
		++strs;
	}
}

char		**ft_multi_strsplit(int argc, char **argv, int *len)
{
	char	**strs;
	char	**tmp_strs;
	char	**tmp;
	int		i;

	i = 1;
	*len = 0;
	strs = NULL;
	while (i < argc)
	{
		tmp = ft_strsplit(argv[i], ' ');
		tmp_strs = strs;
		strs = ft_strlistjoin(tmp_strs, tmp);
		*len += ft_strlistlen(tmp);
		free(tmp_strs);
		tmp_strs = NULL;
		free(tmp);
		tmp = NULL;
		++i;
	}
	return (strs);
}
