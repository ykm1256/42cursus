/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:02:37 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/14 14:54:18 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_info
{
	struct s_stack	*head;
	struct s_stack	*tail;
}	t_stack_info

#endif
