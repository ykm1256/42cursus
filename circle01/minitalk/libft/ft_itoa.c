/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:53:23 by kyoon             #+#    #+#             */
/*   Updated: 2021/07/02 15:04:10 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	num;

	len = ft_numlen(n);
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	num = n;
	while (len-- && !str[len])
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
