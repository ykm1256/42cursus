/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:14:03 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/21 16:24:07 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_stacklen(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i-2);
}

int	ft_free(t_stack_info **info)
{
	t_stack	*stack;
	t_stack *tmp;

	stack = (*info)->a_head;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = (*info)->b_head;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	if (*info)
		free(*info);
	return (0);
}

int	ft_isdigit_str(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_int(char *str)
{
	unsigned long	num;
	int				cnt;
	int				flag;

	num = 0;
	cnt = 0;
	flag = 1;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9' && cnt++ <= 19)
		num = num * 10 + *str++ - '0';
	if (((num > INT_MAX) || (cnt > 19)) && (flag == 1))
		return (0);
	else if (((num > INT_MAX + 1) || (cnt > 19)) && (flag == -1))
		return (0);
	return (1);
}

int	ft_init(char **str, t_stack_info **info)
{
	t_stack *tmp;
	t_stack *a_head;
	t_stack *a_tail;

	a_head = (*info)->a_head;
	a_tail = (*info)->a_tail;
	while (*str)
	{
		if (!ft_isdigit_str(*str) || !is_int(*str))
			return (ft_free(info));
		tmp = ft_newstack(ft_atoi(*str));
		if (!tmp)
			return (ft_free(info));
		ft_stkadd_back(a_head, a_tail, tmp);
		str++;
	}
	return (1);
}


int	ft_init_info(t_stack_info **info)
{
	*info = malloc(sizeof(t_stack_info) * 1);
	if (!(*info))
		return (ft_free(info));
	(*info)->a_head = ft_newstack(0);
	(*info)->a_tail = ft_newstack(0);
	(*info)->b_head = ft_newstack(0);
	(*info)->b_tail = ft_newstack(0);

	((*info)->a_head)->next = (*info)->a_tail;
	((*info)->b_head)->next = (*info)->b_tail;
	((*info)->a_tail)->prev = (*info)->a_head;
	((*info)->b_tail)->prev = (*info)->b_head;
	if (!((*info)->a_head) || !((*info)->a_tail) || !((*info)->b_head) || !((*info)->b_tail))
		return (ft_free(0));
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_info	*info;

	if (!ft_init_info(&info))
	{
		write(2, "Error", 5);
		return (0);
	}
	while (*(++argv))
	{
		if(!ft_init(ft_split(*argv, ' '), &info))
		{
			write(2, "Error", 5);
			return (0);
		}
	}
	if (!ft_sort(info))
	{
		write(2, "Error", 5);
		return (0);
	}

///////////////////////////////////////////////////
	t_stack *a;
	t_stack *b;
	int l = ft_stacklen(info->a_head);

	int i = 0;
	while (i < l)
		ft_putnbr_fd((info->sorted)[i++], 1);

	/*
	a = (info->a_head)->next;
	while (a != info->a_tail)
	{
		ft_putnbr_fd(a->num, 1);
		a = a->next;
	}
	a = (info->a_tail)->prev;
	while (a != info->a_head)
	{
		ft_putnbr_fd(a->num, 1);
		a = a->prev;
	}
	*/

////////////////////////////////////////////////////
		return 0;
}
