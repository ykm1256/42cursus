/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:26:37 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/29 22:12:30 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	log_print(t_philo *philo, char *str, int offset)
{
	struct timeval	now;

	pthread_mutex_lock(philo->prt_mutex);
	if (*(philo->is_die) || *(philo->is_end))
	{
		pthread_mutex_unlock(philo->prt_mutex);
		return (0);
	}
	gettimeofday(&now, NULL);
	if (offset)
	{
		philo->last_eat = now;
		(philo->cnt_eat)++;
	}
	printf("%d %d ", cal_time(philo->start_time, now), philo->number);
	printf("%s\n", str);
	pthread_mutex_unlock(philo->prt_mutex);
	return (1);
}

void	*start(void *data)
{
	t_philo	*philo;
	t_fork	*my;
	t_fork	*next;

	philo = (t_philo *)data;
	if (philo->number % 2 == 0)
		ft_usleep(philo->eat * 900);
	my = &((philo->forks)[philo->number - 1]);
	if (philo->number == philo->cnt_philo)
		next = &((philo->forks)[0]);
	else
		next = &((philo->forks)[philo->number]);
	if (philo->cnt_philo == 1)
	{
		ft_usleep(philo->die * 1000);
		return (0);
	}
	while (1)
	{
		if (!loop(philo, my, next))
			break ;
	}
	return (0);
}

int	loop(t_philo *philo, t_fork *my, t_fork *next)
{
	pthread_mutex_lock(&(my->mutex));
	pthread_mutex_lock(&(next->mutex));
	if (!log_print(philo, "has taken a fork", 0)
		|| !log_print(philo, "is eating", 1))
		return (philo_die(my, next));
	ft_usleep(philo->eat * 1000);
	if (!log_print(philo, "is sleeping", 0))
		return (philo_die(my, next));
	pthread_mutex_unlock(&(next->mutex));
	pthread_mutex_unlock(&(my->mutex));
	ft_usleep(philo->sleep * 1000);
	if (!log_print(philo, "is thinking", 0))
		return (philo_die(my, next));
	return (1);
}

int	join_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].cnt_philo)
	{
		if (pthread_join(philo[i].tid, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	creat_philo(t_philo *philo)
{
	pthread_t	tid;
	int			i;

	i = 0;
	pthread_create(&tid, NULL, check_end, philo);
	while (i < philo[0].cnt_philo)
	{
		if (i % 2 == 0)
			if (pthread_create(&(philo[i].tid), NULL, start, &(philo[i])))
				return (0);
		i++;
	}
	i = 0;
	while (i < philo[0].cnt_philo)
	{
		if (i % 2 == 1)
			if (pthread_create(&(philo[i].tid), NULL, start, &(philo[i])))
				return (0);
		i++;
	}
	return (1);
}
