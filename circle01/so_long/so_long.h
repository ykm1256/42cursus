/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:05 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/23 17:58:16 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef struct s_drawinfo
{
	void	*mlx;
	void	*win;
	void	*img_land;
	void	*img_chr;
	void	*img_wall;
	void	*img_star;
	void	*img_exit;

}				t_drawinfo;

typedef struct s_mapinfo
{
	int				r_size;
	int				c_size;
	int				x_player;
	int				y_player;
	int				x_exit;
	int				y_exit;
	int				cnt_star;
	int				cnt_player;
	int				cnt_exit;
	unsigned int	cnt_move;
	char			**map;
	t_drawinfo		*d_info;
}				t_mapinfo;

int			is_clear(t_mapinfo *info, t_drawinfo *d_info);
int			end_game(t_mapinfo *info, t_drawinfo *d_info);
int			ft_free(t_mapinfo *info, t_drawinfo *d_info);

int			right_move(t_mapinfo *info, t_drawinfo *d_info);
int			left_move(t_mapinfo *info, t_drawinfo *d_info);
int			down_move(t_mapinfo *info, t_drawinfo *d_info);
int			up_move(t_mapinfo *info, t_drawinfo *d_info);
int			key_press(int keycode, t_mapinfo *info);

void		draw_player(t_mapinfo *info, t_drawinfo *d_info, int i, int j);
int			draw(t_mapinfo *info, t_drawinfo *d_info, int i, int j);
int			set_draw(t_mapinfo *info, t_drawinfo *d_info);

char		*map_read(char *f_name, t_mapinfo *info);
void		error_print(char *str, t_mapinfo *info, t_drawinfo *d_info);
int			is_surrounded(t_mapinfo *info);
int			map_validation(t_mapinfo *info, t_drawinfo *d_info, char *f_name);

t_mapinfo	*set_mapinfo(void);
int			draw_init(t_mapinfo *info, t_drawinfo *d_info);
int			map_init(t_mapinfo *info, char *str);
#endif
