/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:42:04 by kyoon             #+#    #+#             */
/*   Updated: 2022/05/28 18:26:06 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"
#include <signal.h>

static void ft_action(int sig)
{
	static	int	received;
	
	received = 0;

	if (sig == SIGUSR1)
		received++;
	else
	{
		printf("%d", received);
		exit(0);	
	}	
}

static void	ft_kill(int pid, char *str)
{
	int		i;
	char	c;
	
	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int		main(int argc, char *argv[])
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (0);
	printf("Sent     : %d", argv[2]);
	printf("Received : ");
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	ft_kill(atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
