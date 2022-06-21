/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:10:24 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/21 15:15:43 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_rrotate(t_stack *head, t_stack *tail)
{
	t_stack	*tmp;

	tmp = ft_stkpop_back(tail);
	ft_stkadd_front(head, tmp);
}

void	ft_rrotate_a(t_stack *head, t_stack *tail)
{
	ft_rrotate(head, tail);
	write(1, "rra", 3);
}

void	ft_rrotate_b(t_stack *head, t_stack *tail)
{
	ft_rrotate(head, tail);
	write(1, "rrb", 3);
}
