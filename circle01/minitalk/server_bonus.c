/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:35:32 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/06 20:28:46 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_action(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;

	(void)*context;
	if (sig == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		if (!c)
		{
			ft_putstr_fd("\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			ft_putchar_fd(c, 1);
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("SERVER : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	s_sigaction.sa_sigaction = ft_action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
