/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:14 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/22 02:02:19 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_free(t_mapinfo *info, t_drawinfo *d_info)
{
	char **tmp;

	tmp = info->map;
	if (info)
	{
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
	if(d_info)
		free(d_info);
	return (0);
}

int		end_game(t_mapinfo *info, t_drawinfo *d_info)
{
	ft_free(info, d_info);
	exit(0);
}

int		is_clear(t_mapinfo *info, t_drawinfo *d_info)
{
	int	i;
	int	j;

	i = info->x_player;
	j = info->y_player;
	if ((info->map)[i][j] == 'E' && !(info->cnt_star))
		end_game(info, d_info);
	return (0);
}

int		right_move(t_mapinfo *info, t_drawinfo *d_info)
{
	if (info->c_size <= info->y_player + 1 ||
			(info->map)[info->x_player][info->y_player + 1] == '1')
		return (0);
	(info->y_player)++;
	if (!is_clear(info, d_info))
	{
		draw(info, d_info, info->x_player, info->y_player - 1);
		draw_player(info, d_info, info->x_player, info->y_player);
	}
	if ((info->map)[info->x_player][info->y_player] == 'C')
	{
		(info->map)[info->x_player][info->y_player] = '0';
		(info->cnt_star)--;
	}
	(info->cnt_move)++;
	printf("moves : %d\n", info->cnt_move);
	return (1);
}

int		left_move(t_mapinfo *info, t_drawinfo *d_info)
{
	if (info->y_player == 0 ||
			(info->map)[info->x_player][info->y_player - 1] == '1')
		return (0);
	(info->y_player)--;
	if (!is_clear(info, d_info))
	{
		draw(info, d_info, info->x_player, info->y_player + 1);
		draw_player(info, d_info, info->x_player, info->y_player);
	}
	if ((info->map)[info->x_player][info->y_player] == 'C')
	{
		(info->map)[info->x_player][info->y_player] = '0';
		(info->cnt_star)--;
	}
	(info->cnt_move)++;
	printf("moves : %d\n", info->cnt_move);
	return (1);
}

int		down_move(t_mapinfo *info, t_drawinfo *d_info)
{
	if (info->r_size <= info->x_player + 1 ||
			(info->map)[info->x_player + 1][info->y_player] == '1')
		return (0);
	(info->x_player)++;
	if (!is_clear(info, d_info))
	{
		draw(info, d_info, info->x_player - 1, info->y_player);
		draw_player(info, d_info, info->x_player, info->y_player);
	}
	if ((info->map)[info->x_player][info->y_player] == 'C')
	{
		(info->map)[info->x_player][info->y_player] = '0';
		(info->cnt_star)--;
	}
	(info->cnt_move)++;
	printf("moves : %d\n", info->cnt_move);
	return (1);
}

int		up_move(t_mapinfo *info, t_drawinfo *d_info)
{
	if (info->x_player == 0 ||
			(info->map)[info->x_player - 1][info->y_player] == '1')
		return (0);
	(info->x_player)--;
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
	(info->cnt_move)++;
	printf("moves : %d\n", info->cnt_move);
	return (1);
}

int		key_press(int keycode, t_mapinfo *info)
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

int		draw_init(t_mapinfo *info, t_drawinfo *d_info)
{
	int img_width;
	int	img_height;

	d_info->mlx = mlx_init();
	d_info->win = mlx_new_window(d_info->mlx,
			 info->c_size * 64, info->r_size * 64, "so_long");
	d_info->img_land = mlx_xpm_file_to_image(d_info->mlx,
			"./land.xpm", &img_width, &img_height);
	d_info->img_chr = mlx_xpm_file_to_image(d_info->mlx,
			"./player.xpm", &img_width, &img_height);
	d_info->img_wall = mlx_xpm_file_to_image(d_info->mlx,
			"./wood.xpm", &img_width, &img_height);
	d_info->img_star = mlx_xpm_file_to_image(d_info->mlx,
			"./star.xpm", &img_width, &img_height);
	d_info->img_exit = mlx_xpm_file_to_image(d_info->mlx,
			"./exit.xpm", &img_width, &img_height);
	return (1);
}

int		map_init(t_mapinfo *info, char *str)
{
	char	**tmp;
	int		col;
	int		row;

	col = 0;
	row = 0;
	tmp = ft_split(str, '\n');
	printf("===========================line==================\n");
	printf("%s\n", str);
	free(str);
	info->map = tmp;
	while (*tmp)
	{
		if (!col)
			col = ft_strlen(*tmp);
		else
		{
			if (col != ft_strlen(*tmp))
				return (0);
		}
		tmp++;
		row++;
	}
	info->r_size = row;
	info->c_size = col;
	return (1);
}

char	*map_read(char *f_name, t_mapinfo *info)
{
	char	s;
	char	*ret;
	int		fd;

	s = 0;
	ret = ft_calloc(1, 1);
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (0 < read(fd, &s, 1))
	{
		if (s == 'P')
			(info->cnt_player)++;
		else if (s == 'E')
			(info->cnt_exit)++;
		else if (s == 'C')
			(info->cnt_star)++;
		ret = ft_strjoin(ret, &s);
		if (!ret)
		{
			free(ret);
			break ;
		}
	}
	return (ret);
}

void	draw_player(t_mapinfo *info, t_drawinfo *d_info, int i, int j)
{
	mlx_put_image_to_window(d_info->mlx,
			d_info->win, d_info->img_chr, j * 64, i * 64);
	info->x_player = i;
	info->y_player = j;
}

int		draw(t_mapinfo *info, t_drawinfo *d_info, int i, int j)
{
	mlx_put_image_to_window(d_info->mlx,
			d_info-> win, d_info->img_land, j * 64, i * 64);
	if ((info->map)[i][j] == '1')
		mlx_put_image_to_window(d_info->mlx,
				d_info->win, d_info->img_wall, j * 64, i * 64);
	else if ((info->map)[i][j] == 'P')
		mlx_put_image_to_window(d_info->mlx,
				d_info->win, d_info->img_chr, j * 64, i * 64);
	else if	((info->map)[i][j] == 'C')
		mlx_put_image_to_window(d_info->mlx,
				d_info->win, d_info->img_star, j * 64, i * 64);
	else if	((info->map)[i][j] == 'E')
		mlx_put_image_to_window(d_info->mlx,
				d_info->win, d_info->img_exit, j * 64, i * 64);
	return (0);
}

int		set_draw(t_mapinfo *info, t_drawinfo *d_info)
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
	mlx_loop(d_info->mlx);
	return (0);
}

void	error_print(char *str, t_mapinfo *info, t_drawinfo *d_info)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}

int		is_surrounded(t_mapinfo *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < info->c_size - 1)
		if ((info->map)[i][j++] != '1')
			return (0);
	while (i < info->r_size - 1)
		if ((info->map)[i++][j] != '1')
			return (0);
	while (0 < j)
		if ((info->map)[i][j--] != '1')
			return (0);
	while (0 < i)
		if ((info->map)[i--][j] != '1')
			return (0);
	return (1);
}

t_mapinfo	*set_mapinfo()
{
	t_mapinfo	*info;

	info = malloc(sizeof(t_mapinfo) * 1);
	ft_bzero(info, sizeof(t_mapinfo));
	return (info);
}

int		map_validation(t_mapinfo *info, t_drawinfo *d_info, char *f_name)
{
	char	*s;

	s = map_read(f_name, info);
	if (!s)
		(error_print("Map can't open.\n", info, d_info));
	if (info->cnt_player == 0)
		(error_print("There is no player", info, d_info));
	if (1 < info->cnt_player)
		(error_print("There is more than one player.\n", info, d_info));
	if (info->cnt_star == 0)
		(error_print("There is no star.\n", info, d_info));
	if ((info->cnt_exit) == 0)
		(error_print("There is no exit.\n", info, d_info));
	if (!map_init(info, s))
		(error_print("Map doesn't fit the format.\n", info, d_info));
	if (!is_surrounded(info))
		(error_print("Map is not surrounded.\n", info, d_info));
	return (1);
}


int		main(int argc, char **argv)
{
	t_mapinfo	*info;
	t_drawinfo	*d_info;
	char		**tmp;

	info = set_mapinfo();
	d_info = malloc(sizeof(t_drawinfo) * 1);
	info->d_info = d_info;
	info->r_size = 0;
	info->c_size = 0;
	if (!map_validation(info, d_info, argv[1]) || !draw_init(info, d_info))
		return (ft_free(info, d_info));
	set_draw(info, d_info);
	ft_free(info, d_info);
	return (1);
}
