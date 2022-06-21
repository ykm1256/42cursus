/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:18:24 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/21 16:32:28 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_move_b(t_stack_info *info)
{
	int	piv1;
	int	piv2;
	int	l;
	t_stack *start;

	piv1 = 0;
	piv2 = piv1 + (int)(0.000000053 * size * size + 0.03 * size + 14.5);
	start = info->head->next;
	l = info->len;
	while (1 < l)
	{
		if (info->len < piv2)
			piv2 = info->len-1;
		if ((info->sorted)[piv2] <= start->num)
			ft_rotate_a(info->a_head, info->a_tail);
		else
		{
			ft_push_b(info->a_head, info->b_head);
			if ((info->sorted)[piv1] < start->num)
				ft_rotate_b(info->b_head, info->b_tail);
			piv1++;
			piv2++;
			l--;
		}
	}
}
