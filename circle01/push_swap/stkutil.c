/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:33:28 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/21 15:15:50 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_stkpop_back(t_stack *tail)
{
	t_stack *tmp;

	tmp = tail->prev;
	tail->prev = tmp->prev;
	tail->prev->next = tail;
	return (tmp);
}

t_stack	*ft_stkpop_front(t_stack *head)
{
	t_stack *tmp;

	tmp = head->next;
	head->next = tmp->next;
	head->next->prev = head;
	return (tmp);
}

void	ft_stkadd_front(t_stack *head, t_stack *new)
{
	new->next = head->next;
	new->prev = head;
	head->next = new;
	new->next->prev = new;
}

void	ft_stkadd_back(t_stack *head, t_stack *tail, t_stack *new)
{
	t_stack *tmp;

	tmp = tail->prev;
	tmp->next = new;
	new->prev = tmp;
	new->next = tail;
	tail->prev = new;
}

t_stack	*ft_newstack(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack) * 1);
	if (!new)
		return (0);
	(*new).num = num;
	(*new).next = 0;
	return (new);
}
