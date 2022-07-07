/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:14 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/08 06:21:40 by kyoon            ###   ########.fr       */
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
	int		x_size;
	char	**map;
}				t_mapinfo;

char	*map_read(char *f_name)
{
	char	*s;
	char	*ret;
	int		fd;

	s = malloc(1);
	ret = calloc(1, 1);
	if (!s)
		return (0);
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

int		main(int argc, char **argv)
{
	t_mapinfo	*info;
	char		**tmp;
	char		*s;

	info = malloc(sizeof(t_mapinfo) * 1);
	s = map_read(argv[1]);
	info->map = ft_split(s, '\n');
	free(s);
	tmp = info->map;

	while (*tmp)
	{
		write(1, *tmp, ft_strlen(*tmp));
		write(1, "\n", 1);
		tmp++;
	}

	return (0);
}


/*
int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	*img_land;
	void	*img_chr;
	
	void	*img_wall;
	void	*img_col;
	void	*img_exit;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");
	img_land = mlx_xpm_file_to_image(mlx, "./grass.xpm", &img_width, &img_height);
	img_chr = mlx_xpm_file_to_image(mlx, "./player.xpm", &img_width, &img_height);
	
	mlx_put_image_to_window(mlx, win, img_land, 0, 0);
	mlx_put_image_to_window(mlx, win, img_chr, 128,0);
	mlx_loop(mlx);
	return (0);
}
*/
