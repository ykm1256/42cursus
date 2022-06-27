/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:14:03 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/27 17:12:33 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_free(t_deque_info **info)
{
	t_deque	*deque;
	t_deque	*tmp;

	deque = (*info)->a_head;
	while (deque)
	{
		tmp = deque->next;
		free(deque);
		deque = tmp;
	}
	deque = (*info)->b_head;
	while (deque)
	{
		tmp = deque->next;
		free(deque);
		deque = tmp;
	}
	if ((*info)->sorted)
		free((*info)->sorted);
	if (*info)
		free(*info);
	return (0);
}

static int	ft_split_free(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	if (str)
		free(str);
	return (0);
}

static int	ft_init(char **str, t_deque_info **info)
{
	t_deque	*tmp;
	t_deque	*a_head;
	t_deque	*a_tail;
	char	**fre;

	fre = str;
	a_head = (*info)->a_head;
	a_tail = (*info)->a_tail;
	while (*str)
	{
		if (!ft_isdigit_str(*str) || !is_int(*str))
			return (ft_free(info) || ft_split_free(fre));
		tmp = ft_newdeque(ft_atoi(*str));
		if (!tmp)
			return (ft_free(info) || ft_split_free(fre));
		ft_deqadd_back(a_tail, tmp);
		str++;
	}
	ft_split_free(fre);
	return (1);
}

static int	ft_init_info(t_deque_info **info)
{
	*info = malloc(sizeof(t_deque_info) * 1);
	if (!(*info))
		return (ft_free(info));
	(*info)->sorted = 0;
	(*info)->a_head = ft_newdeque(0);
	(*info)->a_tail = ft_newdeque(0);
	(*info)->b_head = ft_newdeque(0);
	(*info)->b_tail = ft_newdeque(0);
	((*info)->a_head)->next = (*info)->a_tail;
	((*info)->b_head)->next = (*info)->b_tail;
	((*info)->a_tail)->prev = (*info)->a_head;
	((*info)->b_tail)->prev = (*info)->b_head;
	if (!((*info)->a_head) || !((*info)->a_tail) \
			|| !((*info)->b_head) || !((*info)->b_tail))
		return (ft_free(info));
	return (1);
}

int	main(int argc, char **argv)
{
	t_deque_info	*info;

	if (argc <= 1)
		return (0);
	if (!ft_init_info(&info))
		return (ft_print_err());
	while (*(++argv))
	{
		if (!ft_init(ft_split(*argv, ' '), &info))
			return (ft_print_err());
	}
	if (!ft_sort(info))
		return (ft_print_err());
	if (!is_sorted(info))
	{
		if (info->len <= 5)
			ft_lowpro(info);
		else
			ft_progress(info);
	}
	ft_free(&info);
	return (1);
}
