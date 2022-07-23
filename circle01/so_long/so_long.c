/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:14 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/23 18:07:01 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_init(t_mapinfo *info, t_drawinfo *d_info)
{
	int	img_width;
	int	img_height;

	d_info->mlx = mlx_init();
	d_info->win = mlx_new_window(d_info->mlx,
			info->c_size * 64, info->r_size * 64, "so_long");
	d_info->img_land = mlx_xpm_file_to_image(d_info->mlx,
			"./imgs/land.xpm", &img_width, &img_height);
	d_info->img_chr = mlx_xpm_file_to_image(d_info->mlx,
			"./imgs/player.xpm", &img_width, &img_height);
	d_info->img_wall = mlx_xpm_file_to_image(d_info->mlx,
			"./imgs/wood.xpm", &img_width, &img_height);
	d_info->img_star = mlx_xpm_file_to_image(d_info->mlx,
			"./imgs/star.xpm", &img_width, &img_height);
	d_info->img_exit = mlx_xpm_file_to_image(d_info->mlx,
			"./imgs/exit.xpm", &img_width, &img_height);
	return (1);
}

int	map_init(t_mapinfo *info, char *str)
{
	char			**tmp;
	unsigned int	col;
	unsigned int	row;

	col = 0;
	row = 0;
	tmp = ft_split(str, '\n');
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

t_mapinfo	*set_mapinfo(void)
{
	t_mapinfo	*info;

	info = malloc(sizeof(t_mapinfo) * 1);
	ft_bzero(info, sizeof(t_mapinfo));
	return (info);
}

int	main(int argc, char **argv)
{
	t_mapinfo	*info;
	t_drawinfo	*d_info;

	if (argc != 2)
		error_print("Map name Error.\n", 0, 0);
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
