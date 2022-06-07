/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:08:24 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/22 16:01:50 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char c)
{
	if (c == '.' || c == '+' || c == '-' || c == '#' || c == '*'
	|| c == ' ' || c == 'l' || c == 'h')
		return (1);
	return (0);
}

char	*ft_full_zero(char *str, int *len, t_flags *flags, int offset)
{
	char	*tmp;
	int		t_len;
	int		idx1;
	int		idx2;

	idx1 = -1;
	idx2 = -1;
	t_len = *len;
	if (*len - offset < flags->precision)
	{
		*len = flags->precision + offset;
		if (!(tmp = ft_calloc(sizeof(char), (*len + 1))))
			return (0);
		while (++idx1 < offset)
			tmp[idx1] = str[idx1];
		while (++idx2 < flags->precision - (t_len - offset))
			tmp[idx1++] = '0';
		idx1--;
		while (idx1++ < *len)
			tmp[idx1] = str[idx1 - idx2];
		free(str);
		return (tmp);
	}
	return (str);
}

int		ft_no_end_flag(char **in, t_flags *flags)
{
	char	*str;
	int		len;
	int		ret;

	ret = 0;
	flags->precision = -1;
	if (!(str = ft_calloc(sizeof(char), 2)))
		return (-1);
	str[0] = **in;
	len = ft_strlen(str);
	if (!(str = ft_full_zero(str, &len, flags, 0)))
		return (-1);
	ret = ft_print_line(in, flags, len, str);
	free(str);
	return (ret);
}

int		ft_print_space(char **in, t_flags *flags, int len)
{
	int		ret;
	int		space;
	int		i;
	char	c;

	c = ' ';
	i = -1;
	ret = 0;
	if ((**in == 's' || flags->precision == -1) && flags->zero && !flags->hypen)
		c = '0';
	if (flags->precision > len)
		space = flags->width - flags->precision - ret;
	else
		space = flags->width - len - ret;
	while (++i < space)
		write(1, &c, 1);
	return (ret + i);
}

int		ft_print_line(char **in, t_flags *flags, int len, char *str)
{
	int	ret;

	ret = len;
	if (!flags->hypen)
		ret += ft_print_space(in, flags, len);
	write(1, str, len);
	if (flags->hypen)
		ret += ft_print_space(in, flags, len);
	return (ret);
}
