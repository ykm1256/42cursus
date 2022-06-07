/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:00:42 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/21 16:43:59 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_check_n(char **in)
{
	int	i;

	i = 1;
	while (ft_is_flag((*in)[i]) || ft_isdigit((*in)[i]))
		i++;
	if ((*in)[i] == 'n')
		return (i);
	return (0);
}

int				ft_in_n(char **in, va_list ap, int ret)
{
	int			i;
	int			*tmp;

	if (!(i = ft_check_n(in)))
		return (ft_printf_sub(in, ap));
	else
	{
		tmp = va_arg(ap, signed int*);
		*tmp = ret;
		(*in) += i;
		return (0);
	}
}
