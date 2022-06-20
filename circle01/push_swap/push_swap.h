/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:02:37 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/16 18:11:10 by kyoon            ###   ########.fr       */
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
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_info
{
	struct s_stack	*a_head;
	struct s_stack	*a_tail;
	struct s_stack	*b_head;
	struct s_stack	*b_tail;
}	t_stack_info;

t_stack	*ft_newstack(int num);
int	ft_init_info(t_stack_info **info);
int	ft_ini(char **str, t_stack_info **info);
int	ft_isdigit_str(char *str);
void	ft_free(t_stack_info **info);
int	ft_stacklen(char **str);
void	ft_stkadd_back(t_stack *head, t_stack *tail, t_stack *new);
t_stack	*ft_newstack(int num);


#endif
