/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:26:42 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/29 21:45:38 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	philo_die(t_fork *my, t_fork *next)
{
	pthread_mutex_unlock(&(next->mutex));
	pthread_mutex_unlock(&(my->mutex));
	return (0);
}

int	check_full(t_philo *philo, int *cnt)
{
	if (0 <= philo->must_eat && philo->must_eat <= philo->cnt_eat)
	{
		(*cnt)++;
		if (*cnt == philo->cnt_philo)
		{
			*(philo->is_end) = 1;
			return (0);
		}
	}
	return (1);
}

int	check_die(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (philo->die < cal_time(philo->last_eat, now))
	{
		*(philo->is_die) = 1;
		gettimeofday(&now, NULL);
		printf("%d %d died\n", cal_time(philo->start_time, now), philo->number);
		return (0);
	}
	return (1);
}

void	*check_end(void	*data)
{
	int		i;
	t_philo	*philo;
	int		flag;
	int		cnt;

	flag = 1;
	philo = (t_philo *)data;
	while (flag)
	{
		i = 0;
		cnt = 0;
		ft_usleep(500);
		while (flag && i < philo[0].cnt_philo)
		{
			pthread_mutex_lock(philo[0].prt_mutex);
			flag = check_die(&(philo[i]));
			if (0 <= philo->must_eat)
				flag = check_full(&(philo[i]), &cnt);
			pthread_mutex_unlock(philo[0].prt_mutex);
			i++;
		}
	}
	return (0);
}
