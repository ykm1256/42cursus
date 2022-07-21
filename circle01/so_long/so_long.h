/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:05 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/22 00:53:50 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx/mlx.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2


typedef struct	s_drawinfo
{
	void	*mlx;
	void	*win;
	void	*img_land;
	void	*img_chr;
	void	*img_wall;
	void	*img_star;
	void	*img_exit;

}				t_drawinfo;

typedef struct	s_mapinfo
{
	int			r_size;
	int			c_size;
	int			x_player;
	int			y_player;
	int			x_exit;
	int			y_exit;
	int			cnt_star;
	int			cnt_player;
	int			cnt_exit;
	int			cnt_move;
	char		**map;
	t_drawinfo	*d_info;
}				t_mapinfo;

void	draw_player(t_mapinfo *info, t_drawinfo *d_info, int i, int j);
int	draw(t_mapinfo *info, t_drawinfo *d_info, int i, int j);
int	is_clear(t_mapinfo *info, t_drawinfo *d_info);
#endif
