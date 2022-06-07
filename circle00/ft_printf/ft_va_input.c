/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:01:11 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/21 17:26:24 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_va_unsigned(va_list ap, t_flags *flags)
{
	unsigned long long	num;

	num = 0;
	if (flags->ll)
		num = va_arg(ap, unsigned long long);
	else if (flags->l)
		num = va_arg(ap, unsigned long);
	else if (flags->h)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->hh)
		num = (unsigned char)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, unsigned int);
	return (num);
}

long long			ft_va_decimal(va_list ap, t_flags *flags)
{
	long long num;

	num = 0;
	if (flags->ll)
		num = va_arg(ap, long long);
	else if (flags->l)
		num = va_arg(ap, long);
	else if (flags->h)
		num = (short)va_arg(ap, int);
	else if (flags->hh)
		num = (char)va_arg(ap, int);
	else
		num = va_arg(ap, int);
	return (num);
}

unsigned long long	ft_va_hex(va_list ap, t_flags *flags)
{
	unsigned long long num;

	num = 0;
	if (flags->ll)
		num = va_arg(ap, unsigned long long);
	else if (flags->l)
		num = va_arg(ap, unsigned long);
	else if (flags->h)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->hh)
		num = (unsigned char)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, unsigned int);
	return (num);
}

unsigned long long	ft_va_pointer(va_list ap, t_flags *flags)
{
	unsigned long long num;

	num = 0;
	if (flags->ll)
		num = va_arg(ap, unsigned long long);
	else if (flags->h)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->hh)
		num = (unsigned char)va_arg(ap, unsigned int);
	else
		num = va_arg(ap, unsigned long);
	return (num);
}
