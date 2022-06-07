/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:39:59 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/21 14:46:47 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_full_width_sub(int space, int offset, char *str, char **tmp)
{
	int		idx1;
	int		idx2;
	int		len;

	idx1 = -1;
	idx2 = -1;
	len = ft_strlen(str);
	while (++idx1 < offset)
		(*tmp)[idx1] = str[idx1];
	while (++idx2 < space)
		(*tmp)[idx1++] = '0';
	while (str[idx1 - idx2])
	{
		(*tmp)[idx1] = str[idx1 - idx2];
		idx1++;
	}
	free(str);
}

int			ft_full_width(t_flags *flags, int offset, char *str)
{
	char	*tmp;
	int		space;
	int		len;

	len = ft_strlen(str);
	if (flags->precision > len)
		space = flags->width - flags->precision;
	else
	{
		if ((space = flags->width - len) < 0)
			space = 0;
	}
	if (!(tmp = ft_calloc(sizeof(char), space + len + 1)))
	{
		free(str);
		return (-1);
	}
	ft_full_width_sub(space, offset, str, &tmp);
	write(1, tmp, space + len);
	free(tmp);
	return (space + len);
}
