/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:34:55 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/25 13:55:08 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	ft_kill(ft_atoi(argv[1]), argv[2]);
	return (0);
}
