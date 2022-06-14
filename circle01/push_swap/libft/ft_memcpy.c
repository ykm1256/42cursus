/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:55:56 by kyoon             #+#    #+#             */
/*   Updated: 2021/05/08 17:33:09 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	new_dst = dst;
	new_src = (unsigned char *)src;
	i = 0;
	if (!new_dst && !new_src)
		return (dst);
	while (i < size)
	{
		*new_dst = *new_src;
		new_dst++;
		new_src++;
		i++;
	}
	return (dst);
}
