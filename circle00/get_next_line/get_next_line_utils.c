/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:22:30 by kyoon             #+#    #+#             */
/*   Updated: 2021/05/21 16:11:31 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(int cnt, int size)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc(cnt * size);
	if (!arr)
		return (0);
	while (i < cnt * size)
		arr[i++] = 0;
	return (arr);
}

char	*ft_remalloc(char **line, int len)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!(tmp = ft_calloc(sizeof(char), ft_strlen(*line) + len + 1)))
	{
		free((*line));
		return (0);
	}
	while ((*line)[++i])
		tmp[i] = (*line)[i];
	free(*line);
	return (tmp);
}

int		ft_find_enter(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

void	ft_pull_buf(char *str, int n_idx)
{
	int	i;

	i = 0;
	if (!str[n_idx])
		ft_buf_clean(str);
	else
	{
		while (str[n_idx])
			str[i++] = str[n_idx++];
		while (i < BUFFER_SIZE)
			str[i++] = 0;
	}
}
