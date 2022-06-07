/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:14:10 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/22 16:02:16 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_is_end_flag(char c)
{
	if (c == 's' || c == 'c' || c == 'd' || c == 'u' || c == 'p'
			|| c == 'i' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int				ft_print_percent(char **in, va_list ap, t_flags *flags)
{
	int	ret;

	ret = 0;
	if (ft_is_end_flag(**in))
	{
		if ((**in == 's') || (**in == 'c'))
			ret = ft_print_word(in, ap, flags);
		else
			ret = ft_print_num(in, ap, flags);
	}
	else
		ret = ft_no_end_flag(in, flags);
	return (ret);
}

int				ft_printf_sub(char **in, va_list ap)
{
	int		ret;
	t_flags	*flags;

	if (!(flags = malloc(sizeof(t_flags) * 1)))
		return (-1);
	ft_init_struct(flags);
	while (ft_isdigit((*(++(*in)))) || ft_is_flag(**in))
		ft_flags_set(flags, ap, in);
	ret = ft_print_percent(in, ap, flags);
	free(flags);
	return (ret);
}

int				ft_printf(const char *in, ...)
{
	va_list	ap;
	int		ret;
	char	*str;
	int		tmp;

	str = (char *)in;
	ret = 0;
	va_start(ap, in);
	while (*str)
	{
		tmp = 1;
		if (*str == '%')
		{
			if ((tmp = ft_in_n(&str, ap, ret)) == -1)
				return (-1);
		}
		else
			write(1, str, 1);
		if (*str)
			str++;
		ret += tmp;
	}
	va_end(ap);
	return (ret);
}
