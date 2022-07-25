/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:56:36 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/25 21:41:19 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(void *data)
{
	int i = 0;

}

int	main(int argc, char **argv)
{
	int			i;
	int			cnt_philo = 5;
	pthread_t	tid;
	t_philo		*philos;
	struct timeval		startTime;
	struct timeval		endTime;
	double		diffTime;

	i = 1;
	philos = malloc(sizeof(t_philo) * cnt_philo);
	gettimeofday(&startTime, NULL);
	while (i <= cnt_philo)
	{
		sleep(1);
		gettimeofday(&endTime, NULL);
		diffTime = (endTime.tv_sec - startTime.tv_sec) + 
			(( endTime.tv_usec - startTime.tv_usec) / 1000000);
		printf("time : %f\n", diffTime);
	}
	return (0);
}
