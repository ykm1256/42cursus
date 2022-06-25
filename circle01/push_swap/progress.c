/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:18:24 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/25 15:06:51 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_move_b(t_deque_info *info)
{
	int		piv1;
	int		piv2;
	int		l;
	t_deque	*start;

	l = info->len;
	piv1 = 0;
	piv2 = piv1 + (int)(0.000000053 * l * l + 0.03 * l + 14.5);
	start = info->a_head->next;
	while (1 < l)
	{
		if (info->len <= piv2)
			piv2 = (info->len) - 1;
		if ((info->sorted)[piv2] <= start->num)
			ft_rotate_a(info->a_head, info->a_tail);
		else
		{
			ft_push_b(info->a_head, info->b_head);
			if ((info->sorted)[piv1++] < start->num)
				ft_rotate_b(info->b_head, info->b_tail);
			piv2++;
			l--;
		}
		start = info->a_head->next;
	}
}

int	ft_find_idx(t_deque *head, t_deque *tail, int n)
{
	t_deque	*tmp;
	int		i;

	i = 0;
	tmp = head->next;
	while (tmp->num != n && tmp != tail)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	ft_move_a_sub(t_deque_info *info, int idx, int end)
{
	if (end - idx < idx)
		while (idx++ <= end)
			ft_rrotate_b(info->b_head, info->b_tail);
	else
		while (0 < idx--)
			ft_rotate_b(info->b_head, info->b_tail);
	ft_push_a(info->a_head, info->b_head);
}

void	ft_move_a(t_deque_info *info)
{
	int	end;
	int	n;

	end = info->len - 2;
	while (0 <= end)
	{
		n = (info->sorted)[end];
		ft_move_a_sub(info, ft_find_idx(info->b_head, info->b_tail, n), end);
		end--;
	}
}
