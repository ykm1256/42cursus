/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:42:04 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/05 17:36:49 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

static void	ft_action(int sig)
{
	static int	received;

	if (sig == SIGUSR1)
		received++;
	else
	{
		ft_putnbr_fd(received, 2);
		ft_putstr_fd("\n", 2);
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

int	main(int argc, char *argv[])
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (0);
	ft_putstr_fd("Sent     : ", 2);
	ft_putstr_fd(argv[2], 2);
	ft_putstr_fd("Received : ", 2);
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	ft_kill(atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
