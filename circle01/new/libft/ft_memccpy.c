/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:18:36 by kyoon             #+#    #+#             */
/*   Updated: 2021/05/07 10:26:11 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t size)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	new_dst = dst;
	new_src = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		*new_dst = *new_src;
		if (*new_src == (unsigned char)c)
			return (dst + i + 1);
		new_dst++;
		new_src++;
		i++;
	}
	return (0);
}
