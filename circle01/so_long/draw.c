/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:38:37 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/23 18:05:28 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_mapinfo *info, t_drawinfo *d_info, int i, int j)
{
	mlx_put_image_to_window(d_info->mlx,
		d_info->win, d_info->img_chr, j * 64, i * 64);
	info->x_player = i;
	info->y_player = j;
}

int	draw(t_mapinfo *info, t_drawinfo *d_info, int i, int j)
{
	mlx_put_image_to_window(d_info->mlx,
		d_info-> win, d_info->img_land, j * 64, i * 64);
	if ((info->map)[i][j] == '1')
		mlx_put_image_to_window(d_info->mlx,
			d_info->win, d_info->img_wall, j * 64, i * 64);
	else if ((info->map)[i][j] == 'P')
		mlx_put_image_to_window(d_info->mlx,
			d_info->win, d_info->img_chr, j * 64, i * 64);
	else if ((info->map)[i][j] == 'C')
		mlx_put_image_to_window(d_info->mlx,
			d_info->win, d_info->img_star, j * 64, i * 64);
	else if ((info->map)[i][j] == 'E')
		mlx_put_image_to_window(d_info->mlx,
			d_info->win, d_info->img_exit, j * 64, i * 64);
	return (0);
}

static int	close_win(t_mapinfo *info)
{
	return (end_game(info, info->d_info));
}

int	set_draw(t_mapinfo *info, t_drawinfo *d_info)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->r_size)
	{
		j = 0;
		while (j < info->c_size)
		{
			draw(info, d_info, i, j);
			if ((info->map)[i][j] == 'P')
			{
				info->x_player = i;
				info->y_player = j;
				(info->map)[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	mlx_hook(d_info->win, X_EVENT_KEY_RELEASE, 0, &key_press, info);
	mlx_hook(d_info->win, X_EVENT_KEY_EXIT, 0, &close_win, info);
	mlx_loop(d_info->mlx);
	return (0);
}
