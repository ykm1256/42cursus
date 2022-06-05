/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:26:03 by kyoon             #+#    #+#             */
/*   Updated: 2021/07/02 15:08:38 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_correct(char *hay, char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && needle[i] && hay[i])
	{
		if (hay[i] != needle[i])
			return (0);
		i++;
	}
	if (needle[i])
		return (0);
	return (1);
}

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!hay && !len)
		return (0);
	if (needle[i] == 0)
		return (((char *)hay));
	while (i < len && hay[i])
	{
		if (hay[i] == needle[0])
			if (is_correct(&((char *)hay)[i], ((char *)needle), len - i))
				return (&((char *)hay)[i]);
		i++;
	}
	return (0);
}
