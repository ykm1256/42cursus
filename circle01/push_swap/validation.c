/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:37:44 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/27 17:13:22 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_print_err(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	ft_dequelen(t_deque *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i - 2);
}

int	is_sorted(t_deque_info *info)
{
	int		i;
	t_deque	*start;

	i = 0;
	start = info->a_head->next;
	while (i < info->len)
	{
		if ((info->sorted)[i] != start->num)
			return (0);
		i++;
		start = start->next;
	}
	return (1);
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
	else if (((num - 1 > INT_MAX) || (cnt > 19)) && (flag == -1))
		return (0);
	return (1);
}