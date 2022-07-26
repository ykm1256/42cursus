/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:56:36 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/27 03:04:42 by kyoon            ###   ########.fr       */
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	l1;
	int	l2;
	int	i;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	while (i < l1 && i < l2)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	cal_time(struct timeval start, struct timeval end)
{
	return (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
}

int	log_print(t_philo *philo, char *str)
{
	struct timeval	now;

	pthread_mutex_lock(philo->prt_mutex);
	if (*(philo->is_die))
	{
		pthread_mutex_unlock(philo->prt_mutex);
		return (0);
	}
	gettimeofday(&now, NULL);
	if (ft_strcmp(str, "is eating."))
		philo->last_eat = now;
	printf("%d %d ", cal_time(philo->start_time, now), philo->number);
	printf("%s\n", str);
	pthread_mutex_unlock(philo->prt_mutex);
	return (1);
}

int	philo_die(t_fork *my, t_fork *next)
{
	pthread_mutex_unlock(&(my->mutex));
	pthread_mutex_unlock(&(next->mutex));
	return (0);
}

int	loop(t_philo *philo, t_fork *my, t_fork *next)
{
	pthread_mutex_lock(&(my->mutex));
	pthread_mutex_lock(&(next->mutex));
	if (!log_print(philo, "has taken a fork.")
			|| !log_print(philo, "is eating."))
		return (philo_die(my, next));
	usleep(philo->eat * 1000);
	pthread_mutex_unlock(&(my->mutex));
	pthread_mutex_unlock(&(next->mutex));
	if (!log_print(philo, "is sleeping."))
		return (philo_die(my, next));
	usleep(philo->sleep * 1000);
	if (!log_print(philo, "is thinking."))
		return (philo_die(my, next));
	return (1);
}

void	*start(void *data)
{
	t_philo *philo;
	t_fork	*my;
	t_fork	*next;

	philo = (t_philo *)data;
	my = &((philo->forks)[philo->number - 1]);
	if (philo->number == philo->cnt_philo)
		next = &((philo->forks)[0]);
	else
		next = &((philo->forks)[philo->number]);
	while (1)
	{
		if (!loop(philo, my, next))
			break;
	}
	return (0);
}

t_fork	*fork_init(int cnt_philo)
{
	t_fork	*forks;
	int		i;

	i = 0;
	forks = malloc(sizeof(t_fork) * cnt_philo);
	while (i < cnt_philo)
	{
		pthread_mutex_init(&(forks[i].mutex), NULL);
		forks[i].number = i + 1;
		i++;
	}
	return (forks);
}

t_philo	*philo_init(char **argv, int *is_die, struct timeval start_time, pthread_mutex_t *prt_mutex)
{
	t_philo	*philos;
	t_fork	*forks;
	int		i;
	int		cnt_philo;

	i = 0;
	cnt_philo = ft_atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * cnt_philo);
	forks = fork_init(cnt_philo);
	if (!philos || !forks)
		return (0);
	while (i < cnt_philo)
	{
		philos[i].is_die = is_die;
		philos[i].forks = forks;
		philos[i].prt_mutex = prt_mutex;
		philos[i].start_time = start_time;
		philos[i].number = i + 1;
		philos[i].cnt_philo = cnt_philo;
		philos[i].die = ft_atoi(argv[2]);
		philos[i].eat = ft_atoi(argv[3]);
		philos[i].sleep = ft_atoi(argv[4]);
		i++;
	}
	return philos;
}

void	*check_die(void	*data)
{
	int				i;
	t_philo 		*philo;
	int				flag;
	struct timeval	now;
	
	flag = 1;
	philo = (t_philo *)data;
	while (flag)
	{
		i = 0;
		while (flag && i < philo[0].cnt_philo)
		{
			pthread_mutex_lock(philo[0].prt_mutex);
			gettimeofday(&now, NULL);
			if (philo[0].die < cal_time(philo[i].last_eat, now))
			{
				gettimeofday(&now, NULL);
				printf("%d %d died\n", cal_time(philo[0].start_time, now), i);
				flag = 0;
			}
			pthread_mutex_unlock(philo[0].prt_mutex);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	int				is_die;
	pthread_t		tid;
	t_philo			*philos;
	struct timeval	start_time;
	pthread_mutex_t	prt_mutex;

	i = 0;
	is_die = 0;
	pthread_mutex_init(&prt_mutex, NULL);
	gettimeofday(&start_time, NULL);
	philos = philo_init(argv, &is_die, start_time, &prt_mutex);
	if (!philos)
		return (1);
	while (i < philos[0].cnt_philo)
	{
		if (i % 2 == 0)
			if (pthread_create(&(philos[i].tid), NULL, start, &philos[i]))
				return (1);
		i++;
	}
	i = 0;
	while (i < philos[0].cnt_philo)
	{
		if (i % 2 == 1)
			if (pthread_create(&(philos[i].tid), NULL, start, &philos[i]))
				return (1);
		i++;
	}
	i = 0;
	while (i < philos[0].cnt_philo)
	{
		pthread_join(philos[0].tid, NULL);
	}
	return (0);
}
