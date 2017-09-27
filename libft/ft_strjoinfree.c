/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:13:49 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 16:13:05 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}
