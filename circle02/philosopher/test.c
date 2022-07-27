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
	int *test = malloc(1);
	return (0);
}
