/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:23:24 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/27 17:13:01 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_sort_sub(int	*sort, int l)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < l - 1)
	{
		j = i + 1;
		while (j < l)
		{
			if (sort[j] < sort[i])
			{
				tmp = sort[j];
				sort[j] = sort[i];
				sort[i] = tmp;
			}
			else if (sort[j] == sort[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_sort(t_deque_info *info)
{
	t_deque	*tmp;
	int		i;
	int		l;

	tmp = (info->a_head)->next;
	i = 0;
	l = ft_dequelen(info->a_head);
	info->len = l;
	info->sorted = malloc(sizeof(int) * l);
	if (!info->sorted)
		return (ft_free(&info));
	while (tmp != info->a_tail)
	{
		(info->sorted)[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	if (!ft_sort_sub(info->sorted, l))
		return (ft_free(&info));
	return (1);
}