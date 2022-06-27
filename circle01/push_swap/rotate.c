/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:59:42 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/27 17:12:46 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	ft_rotate(t_deque *head, t_deque *tail)
{
	t_deque	*tmp;

	tmp = ft_deqpop_front(head);
	ft_deqadd_back(tail, tmp);
}

void	ft_rotate_a(t_deque *head, t_deque *tail)
{
	ft_rotate(head, tail);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_deque *head, t_deque *tail)
{
	ft_rotate(head, tail);
	write(1, "rb\n", 3);
}
