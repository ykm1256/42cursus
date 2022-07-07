/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:52:53 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/08 06:21:41 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	c_cnt(char const *s, char c)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (cnt);
}

static	int	str_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	char	**ft_free(char **str, int i)
{
	while (i-- > 0)
		free(str[i]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	str = ft_calloc(sizeof(char *), c_cnt(s, c) + 1);
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		str[i] = ft_calloc(sizeof(char), str_len(s, c) + 1);
		if (!str[i])
			return (ft_free(str, i));
		while (*s && *s != c)
			str[i][j++] = *(s++);
		i++;
	}
	return (str);
}
