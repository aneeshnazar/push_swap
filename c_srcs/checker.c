/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:57:05 by anazar            #+#    #+#             */
/*   Updated: 2017/09/04 21:43:06 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_good(char *str)
{
	if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb") &&
		ft_strcmp(str, "ss") && ft_strcmp(str, "pa") &&
		ft_strcmp(str, "pb") &&
		ft_strcmp(str, "ra") && ft_strcmp(str, "rb") &&
		ft_strcmp(str, "rr") && ft_strcmp(str, "rra") &&
		ft_strcmp(str, "rrb") && ft_strcmp(str, "rrr"))
		return (0);
	return (1);
}

static int	is_reading(char **str, t_stack **a, t_stack **b)
{
	int		num;

	num = get_next_line(0, str);
	if (*str && !(is_good(*str)))
		error(a, b);
	if (num == 0)
		return (0);
	else
		return (1);
}

void		checker(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*buf;

	a = init_stack(argc - 1, argv);
	b = NULL;
	buf = NULL;
	while (is_reading(&buf, &a, &b))
	{
		handle_op(&a, &b, buf);
		ft_strdel(&buf);
	}
	if (check_sort(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
}
