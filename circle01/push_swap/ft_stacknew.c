/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:33:28 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/19 18:27:42 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack) * 1);
	if (!new)
		return (0);
	(*new).num = num;
	(*new).next = 0;
	return (new);
}
