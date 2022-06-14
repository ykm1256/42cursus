/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:58:48 by kyoon             #+#    #+#             */
/*   Updated: 2021/06/01 16:29:43 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			dst_len;
	size_t			res;

	dst_len = ft_strlen(dst);
	res = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (size + res);
	if (size > dst_len + 1)
	{
		while (src[i] && (i < size - dst_len - 1))
		{
			dst[i + dst_len] = src[i];
			i++;
		}
	}
	dst[i + dst_len] = '\0';
	return (dst_len + res);
}
