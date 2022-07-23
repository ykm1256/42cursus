/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:37:50 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/23 20:21:52 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(t_mapinfo *info, t_drawinfo *d_info)
{
	char	**tmp;

	if (info)
	{
		tmp = info->map;
		if (tmp)
		{
			while (*tmp)
			{
				free(*tmp);
				tmp++;
			}
			free(info->map);
		}
		free(info);
	}
	if (d_info)
		free(d_info);
	return (0);
}

int	end_game(t_mapinfo *info, t_drawinfo *d_info)
{
	ft_free(info, d_info);
	exit(1);
}

int	is_clear(t_mapinfo *info, t_drawinfo *d_info)
{
	int	i;
	int	j;

	i = info->x_player;
	j = info->y_player;
	if ((info->map)[i][j] == 'E' && !(info->cnt_star))
		return (end_game(info, d_info));
	return (0);
}
