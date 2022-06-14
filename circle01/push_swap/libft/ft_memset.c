/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:44:53 by kyoon             #+#    #+#             */
/*   Updated: 2021/05/06 14:07:42 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t size)
{
	unsigned char	*new_ptr;
	unsigned char	new_val;
	size_t			i;

	new_ptr = ptr;
	new_val = val;
	i = 0;
	while (i < size)
	{
		*new_ptr = new_val;
		new_ptr++;
		i++;
	}
	return (ptr);
}
