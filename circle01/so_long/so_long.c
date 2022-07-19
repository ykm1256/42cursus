/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:14 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/19 14:22:20 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "./libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef struct	s_mapinfo
{
	int		r_size;
	int		c_size;
	char	**map;
}				t_mapinfo;

int		ft_free(t_mapinfo *info, char *str)
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
	if (str)
		free(str);
	return (0);
}

int		map_init(t_mapinfo *info, char *str)
{
	char	**tmp;
	int		col;
	int		row;

	col = 0;
	row = 0;
	tmp = ft_split(str, '\n');
	info->map = tmp;
	while (*tmp)
	{
		if (!col)
			col = ft_strlen(*tmp);
		else
			if (col != ft_strlen(*tmp))
				return ft_free(info, str);
		tmp++;
		row++;
	}
	info->r_size = row;
	info->c_size = col;
	return (1);
}

char	*map_read(char *f_name, t_mapinfo *info)
{
	char	*s;
	char	*ret;
	int		fd;
	int		cnt;

	cnt = 0;
	s = calloc(1, 1);
	ret = calloc(1, 1);
	fd = open(f_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (0 < read(fd, s, 1))
	{
		ret = ft_strjoin(ret, s);
		if (!ret)
			return (0);
	}
	return (ret);
}

int		draw(t_mapinfo *info)
{
	void	*mlx;
	void	*win;
	void	*img_land;
	void	*img_chr;
	void	*img_wall;
	void	*img_star;
	void	*img_exit;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, info->c_size * 64, info->r_size * 64, "test");
	img_land = mlx_xpm_file_to_image(mlx, "./land.xpm", &img_width, &img_height);
	img_chr = mlx_xpm_file_to_image(mlx, "./player.xpm", &img_width, &img_height);
	img_wall = mlx_xpm_file_to_image(mlx, "./wood.xpm", &img_width, &img_height);
	img_star = mlx_xpm_file_to_image(mlx, "./star.xpm", &img_width, &img_height);
	img_exit = mlx_xpm_file_to_image(mlx, "./exit.xpm", &img_width, &img_height);
	while (i < info->r_size)
	{
		j = 0;
		while (j < info->c_size)
		{
			if ((info->map)[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img_wall, j * 64, i * 64);
			else if ((info->map)[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img_chr, j * 64, i * 64);
			else if	((info->map)[i][j] == 'S')
				mlx_put_image_to_window(mlx, win, img_star, j * 64, i * 64);
			else if	((info->map)[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img_exit, j * 64, i * 64);
			else
				mlx_put_image_to_window(mlx, win, img_land, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mapinfo	*info;
	char		**tmp;
	char		*s;

	info = malloc(sizeof(t_mapinfo) * 1);
	info->r_size = 0;
	info->c_size = 0;
	s = calloc(1, 1);
	// 에러처리 필요
	if (!map_init(info, map_read(argv[1], info)))
		return (0);
	write(1, "tttttttttttt", 10);
	draw(info);
	return (0);
}

