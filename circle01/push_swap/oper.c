/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:45:32 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/21 16:07:23 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_swap(t_stack *head)
{
	t_stack	*first;
	t_stack	*second;

	first = ft_stkpop_front(head);
	second = ft_stkpop_front(head);
	ft_stkadd_front(head, first);
	ft_stkadd_front(head, second);
}

void	ft_swap_a(t_stack *head)
{
	ft_swap(head);
	write(1, "sa", 2);
}

void	ft_swap_b(t_stack *head)
{
	ft_swap(head);
	write(1, "b", 2);
}

void	ft_push_a(t_stack *a_head, t_stack *b_head)
{
	t_stack	*tmp;

	tmp = ft_stkpop_front(b_head);
	ft_stkadd_front(a_head, tmp);
	write(1, "pa", 2);
}

void	ft_push_b(t_stack *a_head, t_stack *b_head)
{
	t_stack	*tmp;

	tmp = ft_stkpop_front(a_head);
	ft_stkadd_front(b_head, tmp);
	write(1, "pb", 2);
}
