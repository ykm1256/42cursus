/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:36:02 by kyoon             #+#    #+#             */
/*   Updated: 2021/07/02 15:05:39 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned char	*new_str;

	new_str = (unsigned char *)str;
	while (size--)
	{
		if (*new_str == (unsigned char)c)
			return (new_str);
		new_str++;
	}
	return (0);
}
