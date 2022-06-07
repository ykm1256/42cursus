/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:21:33 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/22 15:25:16 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_base_len(unsigned long long num)
{
	int	ret;

	ret = 0;
	if (!num)
		return (1);
	while (num > 0)
	{
		num /= 16;
		ret++;
	}
	return (ret);
}

static	void	ft_base_sub(char *str, int len, unsigned long long num)
{
	int res;

	res = 0;
	if (num == 0)
	{
		str[len] = '0';
		return ;
	}
	while (num > 0)
	{
		res = num % 16;
		if (res >= 10)
			res += 87;
		else
			res += '0';
		str[len--] = res;
		num /= 16;
	}
}

char			*ft_base(char **in, t_flags *flags, unsigned long long num)
{
	char	*str;
	int		len;

	len = ft_base_len(num);
	if (**in == 'p' || (flags->sharp && num))
		len += 2;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = 0;
	ft_base_sub(str, len - 1, num);
	if (!num && !flags->precision)
		str[0] = 0;
	if (**in == 'p' || (flags->sharp && num))
	{
		str[0] = '0';
		str[1] = 'x';
	}
	return (str);
}
