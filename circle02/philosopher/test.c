/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:54:56 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/25 20:07:31 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*t_function(void *data)
{
	pid_t		pid;
	pthread_t 	tid;
	char		*thread_name;
	int			i;

	pid = getpid();
	tid = pthread_self();
	i = 0;
	thread_name = (char *)data;

	while (i < 3)
	{
		printf("[%s] pid:%u, tid:%x ----- %d\n", thread_name, (unsigned int)pid, (unsigned int)tid, i);
		i++;
		sleep(1);
	}
}

int	main(void)
{
	pthread_t	p_thread[2];
	int			thr_id;
	int			status;
	char *p1 = "thread_1";
	char *p2 = "thread_2";
	char *pm = "thread_m";
	sleep(1);
	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)p1);
	if (thr_id < 0)
	{
		perror("thread create error : ");
		exit(0);
	}
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)p2);
	if (thr_id < 0)
	{
		perror("thread create error : ");
		exit(0);
	}
	t_function((void *)pm);
	pthread_join(p_thread[0], (void *)&status);
	pthread_join(p_thread[1], (void *)&status);
	printf("when end?\n");

	return (0);
}
