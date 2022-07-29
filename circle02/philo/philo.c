/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:56:36 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/29 21:34:08 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int				is_die;
	t_philo			*philo;
	t_setting		*set;
	int				i;

	i = 1;
	if (argc < 5)
		return (0);
	while (i < argc)
	{
		if (!check_input(argv[i]))
			return (1);
		i++;
	}
	is_die = 0;
	set = setting_init(&is_die, argv, argc);
	if (!set)
		return (1);
	philo = philo_init(argv, set);
	if (!philo)
		return (1);
	if (!creat_philo(philo) || !join_philo(philo))
		is_die = 1;
	philo_free(philo);
	return (is_die);
}
