/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:33:02 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/27 02:16:32 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <memory.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_setting
{
	int		must_eat;
	int		*is_die;
	int		*is_end;
	pthread_mutex_t	*prt_mutex;
	struct timeval	start_time;
}		t_setting;

typedef struct	s_fork
{
	pthread_mutex_t	mutex;
	int		number;
	int		cnt_philo;
}				t_fork;

typedef struct	s_philo
{
	pthread_t	tid;
	pthread_mutex_t	*prt_mutex;
	t_fork		*forks;
	int		number;
	int		cnt_philo;
	int		die;
	int		eat;
	int		sleep;
	int		must_eat;
	int		*is_die;
	int		*is_end;
	int		cnt_eat;
	struct timeval	last_eat;
	struct timeval	start_time;
}				t_philo;

t_setting	*setting_free(t_setting *set);
int	fork_free(t_fork *fork);
int	philo_free(t_philo *philo);


#endif
