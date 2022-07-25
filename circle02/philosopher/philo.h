/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:33:02 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/25 21:40:37 by kyoon            ###   ########.fr       */
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

typedef struct	s_philo
{
	pthread_t		*tid;
	int				number;
	int				cnt_philo;
	char			*status;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
}				t_philo;

typedef struct	s_fork
{
	pthread_mutex_t	mutex;
	int				number;
}				t_fork;

#endif
