/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:22:25 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/29 16:35:35 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
