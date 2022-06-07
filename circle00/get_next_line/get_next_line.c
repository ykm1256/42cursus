/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:22:05 by kyoon             #+#    #+#             */
/*   Updated: 2021/05/21 14:34:23 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_linecpy_sub(char **line, char *str)
{
	int i;

	i = 0;
	while ((*line)[i])
		i++;
	while (*str && *str != '\n')
		(*line)[i++] = *(str++);
	(*line)[i] = 0;
}

int		ft_linecpy(char **line, char *str, int *n_idx)
{
	if ((*n_idx = ft_find_enter(str)) >= 0)
	{
		if (!(*line = ft_remalloc(line, *n_idx)))
			return (0);
	}
	else
	{
		if (!(*line = ft_remalloc(line, ft_strlen(str))))
			return (0);
	}
	ft_linecpy_sub(line, str);
	return (1);
}

int		get_next_line_sub(char **line, int *n_idx, char *str)
{
	if (ft_linecpy(line, str, n_idx) == 0)
		return (-1);
	if (*n_idx >= 0)
	{
		ft_pull_buf(str, *n_idx + 1);
		return (1);
	}
	else
	{
		ft_buf_clean(str);
		return (0);
	}
}

void	ft_buf_clean(char *str)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
		str[i++] = 0;
}

int		get_next_line(int fd, char **line)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	int			n_idx;
	int			ret;

	if (read(fd, "", 0) == -1 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!((*line) = ft_calloc(sizeof(char), 1)))
		return (-1);
	while (buf[fd][0] || read(fd, buf[fd], BUFFER_SIZE) > 0)
		if ((ret = get_next_line_sub(line, &n_idx, buf[fd])))
			return (ret);
	ft_buf_clean(buf[fd]);
	return (0);
}
