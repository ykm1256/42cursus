/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:50:32 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/22 15:24:59 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void				ft_hex_toupper(char *str)
{
	int		len;

	len = ft_strlen(str);
	while (--len >= 0)
		str[len] = ft_toupper(str[len]);
}

int							ft_print_hex(char **in, va_list ap, t_flags *flags)
{
	int					ret;
	unsigned long long	num;
	char				*str;
	int					len;
	int					offset;

	offset = 0;
	ret = 0;
	if (!(num = ft_va_hex(ap, flags)))
		flags->sharp = 0;
	if (!(str = ft_base(in, flags, num)))
		return (-1);
	if (flags->sharp)
		offset = 2;
	if (**in == 'X')
		ft_hex_toupper(str);
	len = ft_strlen(str);
	if (!(str = ft_full_zero(str, &len, flags, offset)))
		return (-1);
	if (flags->precision < 0 && !flags->hypen && flags->zero && flags->sharp)
		return (ft_full_width(flags, offset, str));
	ret = ft_print_line(in, flags, len, str);
	free(str);
	return (ret);
}

int							ft_print_p(char **in, va_list ap, t_flags *flags)
{
	int					ret;
	unsigned long long	p;
	char				*str;
	int					len;
	int					offset;

	offset = 2;
	ret = 0;
	p = ft_va_pointer(ap, flags);
	if (!(str = ft_base(in, flags, p)))
		return (-1);
	len = ft_strlen(str);
	if (!(str = ft_full_zero(str, &len, flags, offset)))
		return (-1);
	if (flags->precision >= 0 && flags->precision < len && !p)
		len = flags->precision + 2;
	if (flags->precision < 0 && !flags->hypen && flags->zero)
		return (ft_full_width(flags, offset, str));
	ret = ft_print_line(in, flags, len, str);
	return (ret);
}
