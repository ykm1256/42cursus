/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:35:32 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/06 20:08:51 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_action(int sig)
{
	static unsigned char	c;
	static int				i;

	if (sig == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		if (!c)
			ft_putstr_fd("\n", 1);
		else
			ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_putstr_fd("SERVER : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	while (1)
		pause();
	return (0);
}
