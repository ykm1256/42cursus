/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:19:53 by kyoon             #+#    #+#             */
/*   Updated: 2021/05/20 22:35:17 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	ft_linecpy_sub(char **line, char *str);
int		ft_linecpy(char **line, char *str, int *n_idx);
int		get_next_line(int fd, char **line);
int		get_next_line_sub(char **line, int *n_idx, char *str);
void	ft_buf_clean(char *str);

void	ft_pull_buf(char *str, int n_idx);
char	*ft_calloc(int cnt, int size);
int		ft_strlen(char *str);
char	*ft_remalloc(char **line, int len);
int		ft_find_enter(char *str);

#endif
