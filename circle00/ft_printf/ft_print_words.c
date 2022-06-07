/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:31:26 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/21 15:02:05 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_string(char **in, va_list ap, t_flags *flags)
{
	int		ret;
	char	*str;
	int		len;

	ret = 0;
	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	if (flags->precision > len)
		flags->precision = len;
	ret = ft_print_line(in, flags, len, str);
	return (ret);
}

int		ft_print_char(char **in, va_list ap, t_flags *flags)
{
	int		ret;
	char	c;

	flags->precision = -1;
	c = va_arg(ap, int);
	ret = 0;
	if (!flags->hypen)
		ret += ft_print_space(in, flags, 1);
	write(1, &c, 1);
	ret++;
	if (flags->hypen)
		ret += ft_print_space(in, flags, 1);
	return (ret);
}

int		ft_print_word(char **in, va_list ap, t_flags *flags)
{
	int	ret;

	ret = 0;
	if (**in == 's')
		ret = ft_print_string(in, ap, flags);
	else if (**in == 'c')
		ret = ft_print_char(in, ap, flags);
	return (ret);
}
