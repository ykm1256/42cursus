/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:14:03 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/19 21:29:26 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_stacklen(char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_free(t_stack_info **info)
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
}

int	ft_isdigit_str(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
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
		tmp = ft_newstack(ft_atoi(*str));
		if (!tmp || !ft_isdigit_str(*str))
		{
			ft_free(info);
			return (0);
		}
		ft_stkadd_back(a_head, a_tail, tmp);
		str++;
	}
	return (1);
}


int	ft_init_info(t_stack_info **info)
{
	*info = malloc(sizeof(t_stack_info) * 1);
	if (!(*info))
	{
		ft_free(info);
		return (0);
	}
	(*info)->a_head = ft_newstack(0);
	(*info)->a_tail = ft_newstack(0);
	(*info)->b_head = ft_newstack(0);
	(*info)->b_tail = ft_newstack(0);

	((*info)->a_head)->next = (*info)->a_tail;
	((*info)->b_head)->next = (*info)->b_tail;
	((*info)->a_tail)->prev = (*info)->a_head;
	((*info)->b_tail)->prev = (*info)->b_head;
	if (!((*info)->a_head) || !((*info)->a_tail) || !((*info)->b_head) || !((*info)->b_tail))
	{
		ft_free(info);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
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
///////////////////////////////////////////////////
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
////////////////////////////////////////////////////
		return 0;
}
