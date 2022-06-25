/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:10:24 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/25 13:00:01 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_rrotate(t_deque *head, t_deque *tail)
{
	t_deque	*tmp;

	tmp = ft_deqpop_back(tail);
	ft_deqadd_front(head, tmp);
}

void	ft_rrotate_a(t_deque *head, t_deque *tail)
{
	ft_rrotate(head, tail);
	write(1, "rra\n", 4);
}

void	ft_rrotate_b(t_deque *head, t_deque *tail)
{
	ft_rrotate(head, tail);
	write(1, "rrb\n", 4);
}
