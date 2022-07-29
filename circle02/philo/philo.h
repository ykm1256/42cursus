/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:33:02 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/29 21:48:16 by kyoon            ###   ########.fr       */
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

typedef struct s_setting
{
	int				must_eat;
	int				*is_die;
	int				*is_end;
	pthread_mutex_t	*prt_mutex;
	struct timeval	start_time;
}		t_setting;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				number;
	int				cnt_philo;
}				t_fork;

typedef struct s_philo
{
	pthread_t		tid;
	pthread_mutex_t	*prt_mutex;
	t_fork			*forks;
	int				number;
	int				cnt_philo;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	int				*is_die;
	int				*is_end;
	int				cnt_eat;
	struct timeval	last_eat;
	struct timeval	start_time;
}				t_philo;

int			ft_atoi(const char *str);
int			cal_time(struct timeval start, struct timeval end);
void		ft_usleep(int t);

int			log_print(t_philo *philo, char *str, int offset);
int			creat_philo(t_philo *philo);
int			join_philo(t_philo *philo);
int			loop(t_philo *philo, t_fork *my, t_fork *next);
void		*start(void *data);

int			check_input(char *str);
int			philo_die(t_fork *my, t_fork *next);
int			check_full(t_philo *philo, int *cnt);
int			check_die(t_philo *philo);
void		*check_end(void	*data);

t_fork		*fork_init(int cnt_philo);
t_philo		*philo_init(char **argv, t_setting *set);
t_setting	*setting_init(int *is_die, char **argv, int argc);
void		philo_alloc(t_philo *philo, t_setting *set,
				t_fork *forks, char **av);

t_setting	*setting_free(t_setting *set);
int			fork_free(t_fork *fork);
int			philo_free(t_philo *philo);

#endif
