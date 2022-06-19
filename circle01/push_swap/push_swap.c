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

	stack = (*info)->head;
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
	t_stack *stack;

	*info = malloc(sizeof(t_stack_info) * 1);
	if (!(*info))
	{
		ft_free(info);
		return (0);
	}
	while (*str)
	{

		if (!((*info)->head))
		{
			(*info)->head = ft_newstack(ft_atoi(*str));
			tmp = ((*info)->head)->next;
		}
		if (!tmp || !ft_isdigit_str(*str))
		{
			ft_free(info);
			return (0);
		}
		(*info)->tail = tmp;
		tmp = tmp->next;
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack_info	*info;

	while (*(++argv))
	{
		if(!ft_init(ft_split(*argv, ' '), &info))
		{
			write(2, "Error", 5);
			return (0);
		}
	}
	a = info->head;
	while (a)
	{
		ft_putnbr_fd(a->num, 1);
		a = a->next;
	}
		return 0;
}
