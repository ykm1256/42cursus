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

int	philo_die(t_fork *my, t_fork *next, t_philo *philo)
{
	pthread_mutex_unlock(&(my->mutex));
	pthread_mutex_unlock(&(next->mutex));
	return (0);
}

int	loop(t_philo *philo, t_fork *my, t_fork *next)
{
	pthread_mutex_lock(&(my->mutex));
	pthread_mutex_lock(&(next->mutex));
	if (!log_print(philo, "has taken a fork", 0)
			|| !log_print(philo, "is eating", 1))
		return (philo_die(my, next, philo));
	usleep(philo->eat * 1000);
	pthread_mutex_unlock(&(my->mutex));
	pthread_mutex_unlock(&(next->mutex));
	if (!log_print(philo, "is sleeping", 0))
		return (philo_die(my, next, philo));
	usleep(philo->sleep * 1000);
	if (!log_print(philo, "is thinking", 0))
		return (philo_die(my, next, philo));
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
	if (philo->cnt_philo == 1)
	{
		usleep(philo->die * 1000);
		return (0);
	}
	while (1)
	{
		if (!loop(philo, my, next))
			break;
	}
	printf("thread : %d END!!!\n", philo->number);
	return (0);
}

t_fork	*fork_init(int cnt_philo)
{
	t_fork	*forks;
	int		i;

	i = 0;
	forks = malloc(sizeof(t_fork) * cnt_philo);
	if (!forks)
		return (0);
	while (i < cnt_philo)
	{
		pthread_mutex_init(&(forks[i].mutex), NULL);
		forks[i].number = i + 1;
		forks[i].cnt_philo = cnt_philo;
		i++;
	}
	return (forks);
}

t_philo	*philo_init(char **argv, t_setting *set)
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
	{
		setting_free(set);
		philo_free(philos);
		fork_free(forks);
		return (0);
	}
	while (i < cnt_philo)
	{
		philos[i].must_eat = set->must_eat;
		philos[i].cnt_eat = 0;
		philos[i].is_die = set->is_die;
		philos[i].forks = forks;
		philos[i].prt_mutex = set->prt_mutex;
		philos[i].start_time = set->start_time;
		philos[i].number = i + 1;
		philos[i].cnt_philo = cnt_philo;
		philos[i].die = ft_atoi(argv[2]);
		philos[i].eat = ft_atoi(argv[3]);
		philos[i].sleep = ft_atoi(argv[4]);
		philos[i].is_end = set->is_end;
		philos[i].last_eat = set->start_time;
		i++;
	}
	free(set);
	return philos;
}

void	*check_die(void	*data)
{
	int			i;
	t_philo 		*philo;
	int			flag;
	struct timeval		now;
	int			cnt;
	
	flag = 1;
	philo = (t_philo *)data;
	while (flag)
	{
		i = 0;
		cnt = 0;
		while (flag && i < philo[0].cnt_philo)
		{
			pthread_mutex_lock(philo[0].prt_mutex);
			gettimeofday(&now, NULL);
			if (philo[0].die < cal_time(philo[i].last_eat, now))
			{
				*(philo[0].is_die) = 1;
				gettimeofday(&now, NULL);
				printf("%d %d died\n", cal_time(philo[0].start_time, now), i + 1);
				flag = 0;
			}
			if (0 <= philo[0].must_eat)
			{
				if (philo[0].must_eat <= philo[i].cnt_eat)
					cnt++;
				if (cnt == philo[0].cnt_philo)
				{
					*(philo[0].is_end) = 1;
					flag = 0;
				}
			}
			pthread_mutex_unlock(philo[0].prt_mutex);
			i++;
		}
	}
	return (0);
}

t_setting	*setting_free(t_setting *set)
{
	if (!set)
		return (0);
	if (set->is_die)
		free(set->is_die);
	if (set->is_end)
		free(set->is_end);
	if (set->prt_mutex)
		free(set->prt_mutex);
	free(set);
	return (0);
}

t_setting	*setting_init(int *is_die, char **argv, int argc)
{
	t_setting	*set;
	pthread_mutex_t	*prt_mutex;
	struct timeval	start_time;
	int		*is_end;

	set = malloc(sizeof(t_setting) * 1);
	if (!set)
		return (0);
	is_end = malloc(sizeof(int) * 1);
	prt_mutex = malloc(sizeof(pthread_mutex_t) * 1);
	set->is_end = is_end;
	set->is_die = is_die;
	set->prt_mutex = prt_mutex;
	if (!is_end || !is_die || !prt_mutex)
		return (setting_free(set));
	*is_end = 0;
	pthread_mutex_init(prt_mutex, NULL);
	gettimeofday(&start_time, NULL);
	set->start_time = start_time;
	if (argc == 6)
		set->must_eat = ft_atoi(argv[5]);
	else
		set->must_eat = -1;
	return (set);
}

int	fork_free(t_fork *fork)
{
	int	i;

	i = 0;
	if (!fork)
		return (0);
	while (i < fork->cnt_philo)
	{
		pthread_mutex_destroy(&fork[i].mutex);
		i++;
	}
	free(fork);
	return (0);

}

int	philo_free(t_philo *philo)
{
	if (!philo)
		return (0);
	if (philo->is_end)
		free(philo->is_end);
	fork_free(philo->forks);
	if (philo->prt_mutex)
	{
		pthread_mutex_destroy(philo->prt_mutex);
		free(philo->prt_mutex);
	}
	free(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	int				is_die;
	t_philo			*philos;
	t_setting		*set;
	pthread_t		tid;

	if (argc < 5)
		return (0);
	i = 0;
	is_die = 0;
	set = setting_init(&is_die, argv, argc);
	if (!set)
		return (1);
	philos = philo_init(argv, set);
	if (!philos)
		return (1);
	pthread_create(&tid, NULL, check_die, philos);
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
		pthread_join(philos[i].tid, NULL);
		i++;
	}
	philo_free(philos);
	return (is_die);
}
