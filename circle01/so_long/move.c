/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:38:42 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/23 18:20:22 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	right_move(t_mapinfo *info, t_drawinfo *d_info)
{
	if (info->c_size <= info->y_player + 1
		|| (info->map)[info->x_player][info->y_player + 1] == '1')
		return (0);
	(info->y_player)++;
	(info->cnt_move)++;
	printf("moves : %d\n", info->cnt_move);
	if (is_clear(info, d_info))
		return (1);
	else
	{
		draw(info, d_info, info->x_player, info->y_player - 1);
		draw_player(info, d_info, info->x_player, info->y_player);
	}
	if ((info->map)[info->x_player][info->y_player] == 'C')
	{
		(info->map)[info->x_player][info->y_player] = '0';
		(info->cnt_star)--;
	}
	return (0);
}

int	left_move(t_mapinfo *info, t_drawinfo *d_info)
{
	if (info->y_player == 0
		|| (info->map)[info->x_player][info->y_player - 1] == '1')
		return (0);
	(info->y_player)--;
	(info->cnt_move)++;
	printf("moves : %d\n", info->cnt_move);
	if (is_clear(info, d_info))
		return (1);
	else
	{
		draw(info, d_info, info->x_player, info->y_player + 1);
		draw_player(info, d_info, info->x_player, info->y_player);
	}
	if ((info->map)[info->x_player][info->y_player] == 'C')
	{
		(info->map)[info->x_player][info->y_player] = '0';
		(info->cnt_star)--;
	}
	return (0);
}

int	down_move(t_mapinfo *info, t_drawinfo *d_info)
{
	if (info->r_size <= info->x_player + 1
		|| (info->map)[info->x_player + 1][info->y_player] == '1')
		return (0);
	(info->x_player)++;
	(info->cnt_move)++;
	printf("moves : %d\n", info->cnt_move);
	if (is_clear(info, d_info))
		return (1);
	else
	{
		draw(info, d_info, info->x_player - 1, info->y_player);
		draw_player(info, d_info, info->x_player, info->y_player);
	}
	if ((info->map)[info->x_player][info->y_player] == 'C')
	{
		(info->map)[info->x_player][info->y_player] = '0';
		(info->cnt_star)--;
	}
	return (0);
}

int	up_move(t_mapinfo *info, t_drawinfo *d_info)
{
	if (info->x_player == 0
		|| (info->map)[info->x_player - 1][info->y_player] == '1')
		return (0);
	(info->x_player)--;
	(info->cnt_move)++;
	printf("moves : %d\n", info->cnt_move);
	if (is_clear(info, d_info))
		return (1);
	if (!is_clear(info, d_info))
	{
		draw(info, d_info, info->x_player + 1, info->y_player);
		draw_player(info, d_info, info->x_player, info->y_player);
	}
	if ((info->map)[info->x_player][info->y_player] == 'C')
	{
		(info->map)[info->x_player][info->y_player] = '0';
		(info->cnt_star)--;
	}
	return (1);
}

int	key_press(int keycode, t_mapinfo *info)
{
	t_drawinfo	*d_info;

	d_info = info->d_info;
	if (keycode == KEY_ESC)
		return (end_game(info, d_info));
	if (keycode == KEY_W)
		up_move(info, d_info);
	else if (keycode == KEY_S)
		down_move(info, d_info);
	else if (keycode == KEY_A)
		left_move(info, d_info);
	else if (keycode == KEY_D)
		right_move(info, d_info);
	return (1);
}
