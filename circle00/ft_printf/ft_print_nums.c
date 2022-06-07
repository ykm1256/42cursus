/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:29:56 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/21 17:07:28 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_num(char **in, va_list ap, t_flags *flags)
{
	int	ret;

	ret = 0;
	if (**in == 'i' || **in == 'd')
		ret = ft_print_decimal(in, ap, flags);
	else if (**in == 'x' || **in == 'X')
		ret = ft_print_hex(in, ap, flags);
	else if (**in == 'u')
		ret = ft_print_unsigned(in, ap, flags);
	else
		ret = ft_print_p(in, ap, flags);
	return (ret);
}

int		ft_print_unsigned(char **in, va_list ap, t_flags *flags)
{
	int						ret;
	char					*str;
	int						len;
	unsigned long long		num;
	int						offset;

	offset = 0;
	ret = 0;
	num = ft_va_unsigned(ap, flags);
	if (!(str = ft_pf_itoa_uns(num)))
		return (-1);
	if (!num && !flags->precision)
		str[0] = 0;
	len = ft_strlen(str);
	if (!(str = ft_full_zero(str, &len, flags, 0)))
		return (-1);
	ret = ft_print_line(in, flags, len, str);
	free(str);
	return (ret);
}

void	ft_print_decimal_sub(t_flags *flags, int *offset, int num, char **str)
{
	if (!num && !flags->precision)
		(*str)[*offset] = 0;
	if (num < 0)
	{
		flags->space = 0;
		*offset = 1;
	}
}

int		ft_print_decimal(char **in, va_list ap, t_flags *flags)
{
	int			ret;
	char		*str;
	int			len;
	long long	num;
	int			offset;

	offset = 0;
	ret = 0;
	num = ft_va_decimal(ap, flags);
	if (!(str = ft_pf_itoa(flags, num, &offset)))
		return (-1);
	ft_print_decimal_sub(flags, &offset, num, &str);
	len = ft_strlen(str);
	if (flags->precision < 0 && !flags->hypen && flags->zero && offset)
		return (ft_full_width(flags, offset, str));
	if (!(str = ft_full_zero(str, &len, flags, offset)))
		return (-1);
	ret = ft_print_line(in, flags, len, str);
	free(str);
	return (ret);
}
