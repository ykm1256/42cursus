/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 22:12:32 by kyoon             #+#    #+#             */
/*   Updated: 2021/07/02 15:09:03 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	char	*ft_end(char const *s1, char const *set)
{
	char	*tmp;

	tmp = (char *)s1;
	while (*tmp)
		tmp++;
	while (s1 < tmp--)
		if (!is_set(set, *tmp))
			return (tmp);
	return (0);
}

static	char	*ft_start(char const *s1, char const *set)
{
	char	*tmp;

	tmp = (char *)s1;
	while (*tmp)
	{
		if (!is_set(set, *tmp))
			return (tmp);
		tmp++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	char	*end;

	start = ft_start(s1, set);
	if (!start)
	{
		str = (char *)malloc(1);
		if (!str)
			return (0);
		*str = 0;
		return (str);
	}
	end = ft_end(s1, set);
	return (ft_substr(s1, start - s1, end - start + 1));
}
