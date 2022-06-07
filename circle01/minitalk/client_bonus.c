/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:34:55 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/06 20:27:44 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_action(int sig)
{
	static int	cnt;

	if (sig == SIGUSR1)
		cnt++;
	else
	{
		ft_putnbr_fd(cnt, 1);
		cnt = 0;
		exit(0);
	}
}

static void	ft_kill(int pid, char *str)
{
	char	c;
	int		i;

	while (*str)
	{
		c = *str;
		i = 8;
		while (i)
		{
			if (c >> --i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		str++;
	}
	while (++i <= 8)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	ft_putstr_fd("SEND : ", 1);
	ft_putstr_fd(argv[2], 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("RECEIVE : ", 1);
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
