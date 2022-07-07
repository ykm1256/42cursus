/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:06:56 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/21 12:46:53 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(char str)
{
	if ((9 <= str && str <= 13) || str == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long			num;
	int						flag;
	int						cnt;

	num = 0;
	cnt = 0;
	flag = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9' && cnt++ <= 19)
		num = num * 10 + *str++ - '0';
	if (((num > LONG_MAX) || (cnt > 19)) && (flag == 1))
		return (-1);
	else if (((num > LONG_MAX) || (cnt > 19)) && (flag == -1))
		return (0);
	return (flag * num);
}
