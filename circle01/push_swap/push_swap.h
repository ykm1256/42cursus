/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:02:37 by kyoon             #+#    #+#             */
/*   Updated: 2022/06/25 15:29:37 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_deque
{
	int				num;
	struct s_deque	*prev;
	struct s_deque	*next;
}	t_deque;

typedef struct s_deque_info
{
	struct s_deque	*a_head;
	struct s_deque	*a_tail;
	struct s_deque	*b_head;
	struct s_deque	*b_tail;
	int				*sorted;
	int				len;
}	t_deque_info;

void	ft_swap_a(t_deque *head);
void	ft_swap_b(t_deque *head);
void	ft_push_a(t_deque *a_head, t_deque *b_head);
void	ft_push_b(t_deque *a_head, t_deque *b_head);

void	ft_rotate_a(t_deque *head, t_deque *tail);
void	ft_rotate_b(t_deque *head, t_deque *tail);

void	ft_rrotate_a(t_deque *head, t_deque *tail);
void	ft_rrotate_b(t_deque *head, t_deque *tail);

t_deque	*ft_deqpop_back(t_deque *tail);
t_deque	*ft_deqpop_front(t_deque *head);
void	ft_deqadd_front(t_deque *head, t_deque *new);
void	ft_deqadd_back(t_deque *tail, t_deque *new);
t_deque	*ft_newdeque(int num);

int		ft_dequelen(t_deque *head);
int		is_sorted(t_deque_info *info);
int		ft_isdigit_str(char *str);
int		is_int(char *str);

void	ft_move_b(t_deque_info *info);
void	ft_move_a(t_deque_info *info);
int		ft_find_idx(t_deque *head, t_deque *tail, int n);

int		ft_sort_sub(int	*sort, int l);
int		ft_sort(t_deque_info *info);

void	ft_lowpro(t_deque_info *info);

int		ft_free(t_deque_info **info);

#endif
