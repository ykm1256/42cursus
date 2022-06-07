/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:15:56 by kyoon             #+#    #+#             */
/*   Updated: 2022/05/25 18:08:26 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int			space;
	int			zero;
	int			width;
	int			precision;
	int			hypen;
	int			sharp;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			plus;
}					t_flags;

int					ft_printf(const char *str, ...);

void				ft_flag_width(char **in, va_list ap, t_flags *flags);
void				ft_init_struct(t_flags *flags);
void				ft_precision(char **in, va_list ap, t_flags *flags);
void				ft_flags_set(t_flags *flags, va_list ap, char **in);

int					ft_full_width(t_flags *flags, int offset, char *str);

int					ft_print_percent(char **in, va_list ap, t_flags *flags);
int					ft_printf_sub(char **in, va_list ap);
int					ft_printf(const char *in, ...);

int					ft_is_flag(char c);
char				*ft_full_zero(char *str, int *len,
t_flags *flags, int offset);
int					ft_no_end_flag(char **in, t_flags *flags);
int					ft_print_space(char **in, t_flags *flags, int len);
int					ft_print_line(char **in, t_flags *flags,
int len, char *str);

int					ft_print_decimal(char **in, va_list ap, t_flags *flags);
int					ft_print_unsigned(char **in, va_list ap, t_flags *flags);
int					ft_print_num(char **in, va_list ap, t_flags *flags);

int					ft_print_hex(char **in, va_list ap, t_flags *flags);
int					ft_print_p(char **in, va_list ap, t_flags *flags);
char				*ft_base(char **in, t_flags *flags, unsigned long long num);

int					ft_print_word(char **in, va_list ap, t_flags *flags);
int					ft_print_char(char **in, va_list ap, t_flags *flags);
int					ft_print_string(char **in, va_list ap, t_flags *flags);

char				*ft_pf_itoa(t_flags *flags, long long n, int *sign);
char				*ft_pf_itoa_uns(unsigned long long n);

unsigned long long	ft_va_unsigned(va_list ap, t_flags *flags);
long long			ft_va_decimal(va_list ap, t_flags *flags);
unsigned long long	ft_va_hex(va_list ap, t_flags *flags);
unsigned long long	ft_va_pointer(va_list ap, t_flags *flags);

int					ft_in_n(char **in, va_list ap, int ret);
#endif
