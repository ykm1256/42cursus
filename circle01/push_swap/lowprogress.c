/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowprogress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:54:05 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/25 14:56:09 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lowpro_sub(t_deque_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->a_head->next->num;
	b = info->a_head->next->next->num;
	c = info->a_head->next->next->next->num;
	if (b < a && c < a)
	{
		ft_rotate_a(info->a_head, info->a_tail);
		if (c < b)
			ft_swap_a(info->a_head);
	}
	if (c < a && a < b && c < b)
	{
		ft_rrotate_a(info->a_head, info->a_tail);
	}
	if (b < a && a < c && b < c)
		ft_swap_a(info->a_head);
	if (a < b && a < c && c < b)
	{
		ft_swap_a(info->a_head);
		ft_rotate_a(info->a_head, info->a_tail);
	}
}

void	ft_lowpro(t_deque_info *info)
{
	int	l;
	int idx;

	l = (info->len) - 1;
	if (info->len == 3)
		ft_lowpro_sub(info);
	else
	{
		while (3 < ft_dequelen(info->a_head))
		{
			idx = ft_find_idx(info->a_head, info->a_tail, (info->sorted)[l]);
			if (l - idx < idx)
				while (idx++ <= l)
					ft_rrotate_a(info->a_head, info->a_tail);
			else
				while (0 < idx--)
					ft_rotate_a(info->a_head, info->a_tail);
			ft_push_b(info->a_head, info->b_head);
			l--;
		}
		ft_lowpro_sub(info);
		while (0 < ft_dequelen(info->b_head))
		{
			ft_push_a(info->a_head, info->b_head);
			ft_rotate_a(info->a_head, info->a_tail);
		}
	}
}
