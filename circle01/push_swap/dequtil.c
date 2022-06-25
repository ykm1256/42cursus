/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequtil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:33:28 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/25 14:26:54 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*ft_deqpop_back(t_deque *tail)
{
	t_deque	*tmp;

	tmp = tail->prev;
	tail->prev = tmp->prev;
	tail->prev->next = tail;
	return (tmp);
}

t_deque	*ft_deqpop_front(t_deque *head)
{
	t_deque	*tmp;

	tmp = head->next;
	head->next = tmp->next;
	head->next->prev = head;
	return (tmp);
}

void	ft_deqadd_front(t_deque *head, t_deque *new)
{
	new->next = head->next;
	new->prev = head;
	head->next = new;
	new->next->prev = new;
}

void	ft_deqadd_back(t_deque *tail, t_deque *new)
{
	t_deque	*tmp;

	tmp = tail->prev;
	tmp->next = new;
	new->prev = tmp;
	new->next = tail;
	tail->prev = new;
}

t_deque	*ft_newdeque(int num)
{
	t_deque	*new;

	new = malloc(sizeof(t_deque) * 1);
	if (!new)
		return (0);
	(*new).num = num;
	(*new).next = 0;
	return (new);
}
