/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:21:49 by kyoon             #+#    #+#             */
/*   Updated: 2022/05/28 18:25:46 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	f(int signum)
{
	printf("Received a USR1\n");
	exit(0);
}

void	g(int signum)
{
	printf("Received a USR2\n");
	exit(0);
}

int 	main(int argc, char *argv[])
{
	void f(int);
	void g(int);

	int i;

	i = 1;
	
	signal(SIGUSR1, f);
	signal(SIGUSR2, g);
	while(i++)
	{
		printf("%dsec\n", i);
		sleep(1);
	}




	/*
	printf("Count down START!\n");
	while (i >= 0)
	{
		printf("%dsec\n", i);
		sleep(1);
		i--;
	}
	*/
}
