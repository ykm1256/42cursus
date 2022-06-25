/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:45:32 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/25 14:32:26 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_swap(t_deque *head)
{
	t_deque	*first;
	t_deque	*second;

	first = ft_deqpop_front(head);
	second = ft_deqpop_front(head);
	ft_deqadd_front(head, first);
	ft_deqadd_front(head, second);
}

void	ft_swap_a(t_deque *head)
{
	ft_swap(head);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_deque *head)
{
	ft_swap(head);
	write(1, "sb\n", 3);
}

void	ft_push_a(t_deque *a_head, t_deque *b_head)
{
	t_deque	*tmp;

	tmp = ft_deqpop_front(b_head);
	ft_deqadd_front(a_head, tmp);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_deque *a_head, t_deque *b_head)
{
	t_deque	*tmp;

	tmp = ft_deqpop_front(a_head);
	ft_deqadd_front(b_head, tmp);
	write(1, "pb\n", 3);
}
