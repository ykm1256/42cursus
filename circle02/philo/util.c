/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:17:35 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/29 21:17:17 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	is_space(char str)
{
	if ((9 <= str && str <= 13) || str == 32)
		return (1);
	else
		return (0);
}

void	ft_usleep(int t)
{
	struct timeval	now;
	struct timeval	start;
	int				sum;

	sum = 0;
	gettimeofday(&start, NULL);
	while (1)
	{
		usleep((t - sum) / 2 + 1);
		gettimeofday(&now, NULL);
		sum = cal_time(start, now) * 1000;
		if (t <= sum)
			return ;
	}
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
	if (((num > 9223372036854775807) || (cnt > 19)) && (flag == 1))
		return (-1);
	else if (((num > 9223372036854775807) || (cnt > 19)) && (flag == -1))
		return (0);
	return (flag * num);
}

int	cal_time(struct timeval start, struct timeval end)
{
	return ((end.tv_sec - start.tv_sec) * 1000
		+ (end.tv_usec - start.tv_usec) / 1000);
}
