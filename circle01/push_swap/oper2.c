/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:59:42 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/21 16:22:04 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_rotate(t_stack *head, t_stack *tail)
{
	t_stack	*tmp;

	tmp = ft_stkpop_front(head);
	ft_stkadd_back(head, tail, tmp);
}

void	ft_rotate_a(t_stack *head, t_stack *tail)
{
	ft_rotate(head, tail);
	write(1, "ra", 2);
}

void	ft_rotate_b(t_stack *head, t_stack *tail)
{
	ft_rotate(head, tail);
	write(1, "rb", 2);
}
