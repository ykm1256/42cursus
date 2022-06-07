/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:53:23 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/21 14:48:06 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_numlen(unsigned long long n)
{
	int		i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char	ft_pf_itoa_sub(t_flags *flags, int *sign, long long n, int *len)
{
	char	c;

	c = ' ';
	if ((flags->space || flags->plus) && n >= 0)
	{
		*sign = 1;
		*len += 1;
	}
	if (flags->plus)
		c = '+';
	if (n < 0)
	{
		c = '-';
		*sign = 1;
		(*len)++;
	}
	return (c);
}

char			*ft_pf_itoa_uns(unsigned long long n)
{
	int			len;
	char		*str;

	len = ft_numlen(n);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char			*ft_pf_itoa(t_flags *flags, long long n, int *sign)
{
	int						len;
	char					*str;
	unsigned long long		num;
	char					c;

	if (n < 0)
		num = n * -1;
	else
		num = n;
	len = ft_numlen(num);
	c = ft_pf_itoa_sub(flags, sign, n, &len);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (0);
	while ((len--) - *sign)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	if (!len)
		str[len] = c;
	return (str);
}
