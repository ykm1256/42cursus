/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:31:05 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/29 18:40:21 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	philo_alloc(t_philo *philo, t_setting *set, t_fork *forks, char **av)
{
	int		i;
	int		cnt_philo;

	i = 0;
	cnt_philo = ft_atoi(av[1]);
	while (i < cnt_philo)
	{
		philo[i].must_eat = set->must_eat;
		philo[i].cnt_eat = 0;
		philo[i].is_die = set->is_die;
		philo[i].forks = forks;
		philo[i].prt_mutex = set->prt_mutex;
		philo[i].start_time = set->start_time;
		philo[i].number = i + 1;
		philo[i].cnt_philo = ft_atoi(av[1]);
		philo[i].die = ft_atoi(av[2]);
		philo[i].eat = ft_atoi(av[3]);
		philo[i].sleep = ft_atoi(av[4]);
		philo[i].is_end = set->is_end;
		philo[i].last_eat = set->start_time;
		i++;
	}
}

t_philo	*philo_init(char **argv, t_setting *set)
{
	t_philo	*philo;
	t_fork	*forks;
	int		cnt_philo;

	cnt_philo = ft_atoi(argv[1]);
	philo = malloc(sizeof(t_philo) * cnt_philo);
	forks = fork_init(cnt_philo);
	if (!philo || !forks)
	{
		setting_free(set);
		philo_free(philo);
		fork_free(forks);
		return (0);
	}
	philo_alloc(philo, set, forks, argv);
	free(set);
	return (philo);
}

t_setting	*setting_init(int *is_die, char **argv, int argc)
{
	t_setting		*set;
	pthread_mutex_t	*prt_mutex;
	struct timeval	start_time;
	int				*is_end;

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
