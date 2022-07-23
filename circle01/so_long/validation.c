/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:44:53 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/23 20:26:47 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_read(char *f_name, t_mapinfo *info)
{
	char	*ret;
	int		fd;
	char	*s;
	char	*tmp;

	s = ft_calloc(1, 2);
	ret = ft_calloc(1, 1);
	fd = open(f_name, O_RDONLY);
	while (0 < read(fd, s, 1))
	{
		(info->cnt_player) += s[0] == 'P';
		(info->cnt_exit) += s[0] == 'E';
		(info->cnt_star) += s[0] == 'C';
		tmp = ret;
		ret = ft_strjoin(ret, s);
		free(tmp);
		if (!ret)
		{
			free(ret);
			break ;
		}
	}
	free(s);
	return (ret);
}

void	error_print(char *str, t_mapinfo *info, t_drawinfo *d_info)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_free(info, d_info);
	exit(1);
}

int	is_surrounded(t_mapinfo *info)
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

int	map_validation(t_mapinfo *info, t_drawinfo *d_info, char *f_name)
{
	char	*s;

	if (ft_strlen(f_name) >= 4
		&& ft_strncmp(&f_name[ft_strlen(f_name) - 4], ".ber", 4))
		error_print("Map is not .ber file.\n", info, d_info);
	if (open(f_name, O_RDONLY) < 0)
		error_print("Map can't open.\n", info, d_info);
	s = map_read(f_name, info);
	if (!s)
		error_print("Map read Error.\n", info, d_info);
	if (info->cnt_player == 0)
		error_print("There is no player", info, d_info);
	if (1 < info->cnt_player)
		error_print("There is more than one player.\n", info, d_info);
	if (info->cnt_star == 0)
		error_print("There is no star.\n", info, d_info);
	if (info->cnt_exit == 0)
		error_print("There is no exit.\n", info, d_info);
	if (!map_init(info, s))
		error_print("Map doesn't fit the format.\n", info, d_info);
	if (!is_surrounded(info))
		error_print("Map is not surrounded.\n", info, d_info);
	return (1);
}
