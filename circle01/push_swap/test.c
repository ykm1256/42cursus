/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:52:37 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/19 21:17:50 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int	main(void)
{
	t_list *list;
	int a = 1;
	int *b = &a;
	char c = 'a';
	char *s = &c;
	list = ft_lstnew(b);


	printf("%d\n", *(int *)(list->content));
}
