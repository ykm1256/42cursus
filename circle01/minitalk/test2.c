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

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int		main(int argc, char *argv[])
{
	if (argc < 3)
		printf("Usage : ./%s PID \n", argv[0]);
	else
	{
		if(atoi(argv[2]) == 1)
			kill(atoi(argv[1]), SIGUSR1);
		else if(atoi(argv[2]) == 2)
		{
			kill(atoi(argv[1]), SIGUSR2);

		}
	}
	//	kill(atoi(argv[1]), 9);

}
