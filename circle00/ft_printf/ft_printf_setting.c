/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:34:17 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/22 15:26:23 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_length(char **in, t_flags *flags)
{
	if (!flags->ll && **in == 'l' && *(*in + 1) == 'l')
	{
		flags->ll = 1;
		*in += 1;
	}
	if (!flags->ll && **in == 'l' && *(*in + 1) != 'l')
		flags->l = 1;
	if (!flags->ll && !flags->l && **in == 'h' && *(*in + 1) != 'h')
		flags->h = 1;
	if (!flags->ll && !flags->l && !flags->h
	&& **in == 'h' && *(*in + 1) == 'h')
	{
		flags->hh = 1;
		*in += 1;
	}
}

void			ft_flag_width(char **in, va_list ap, t_flags *flags)
{
	int	w;

	w = 0;
	if (**in == '*')
		w = va_arg(ap, int);
	else
	{
		w = ft_atoi(*in);
		while (ft_isdigit(**in))
			*in += 1;
		*in -= 1;
	}
	if (w >= 0)
		flags->width = w;
	else
	{
		flags->width = -1 * w;
		flags->hypen = 1;
	}
}

void			ft_init_struct(t_flags *flags)
{
	flags->space = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->hypen = 0;
	flags->sharp = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->h = 0;
	flags->hh = 0;
	flags->plus = 0;
}

void			ft_precision(char **in, va_list ap, t_flags *flags)
{
	int	p;

	p = 0;
	*in += 1;
	if (**in == '*')
	{
		if ((p = va_arg(ap, int)) < 0)
			p = -1;
	}
	else
	{
		p = ft_atoi(*in);
		while (ft_isdigit(**in))
			*in += 1;
		*in -= 1;
	}
	flags->precision = p;
}

void			ft_flags_set(t_flags *flags, va_list ap, char **in)
{
	if (**in == '-')
		flags->hypen = 1;
	else if (**in == '+')
		flags->plus = 1;
	else if (**in == '.')
		ft_precision(in, ap, flags);
	else if (**in == '0')
		flags->zero = 1;
	else if (ft_isdigit(**in) || **in == '*')
		ft_flag_width(in, ap, flags);
	else if (**in == ' ')
		flags->space = 1;
	else if (**in == '#')
		flags->sharp = 1;
	else
		ft_length(in, flags);
}
