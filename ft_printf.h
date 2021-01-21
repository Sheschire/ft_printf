/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:44:25 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/21 11:19:25 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct		s_flags
{
	int		width;
	int		minus;
	int		zero;
	int		dot;
	int		joker;
	int		error;
	int		intneg;
	int		count;
	int		arglen;
}					t_flags;

t_flags		ft_dot_flag(t_flags flags, char *s);
t_flags		ft_minus_flag(t_flags flags, char *s);
t_flags		ft_zero_flag(t_flags flags, char *s);
t_flags		ft_joker_flag(t_flags flags, va_list ap);
t_flags		ft_init_flags(void);
int			ft_printf(const char *input, ...);
int			ft_str_malloc(t_flags flags, char *arg);
int			ft_int_malloc(char *arg, t_flags flags);
int			ft_update_index(char *s, t_flags flags);
int			ft_is_int_convertor(char c);
int			ft_is_char_convertor(char c);
int			ft_is_hexa_convertor(char c);
int			ft_is_convertor(char c);
int			ft_convert(char c, t_flags flags, va_list ap);
int			ft_print_char(char c, va_list ap, t_flags flags);
int			ft_print_int(char *arg, t_flags flags);
int			ft_print_str(char *arg, t_flags flags);
int			ft_putn_and_count(char *s, int n);
int			ft_calculate_malloc(t_flags flags, char *arg, char c);
int			ft_is_flag(char c);
int			ft_is_flags_empty(t_flags f1);

#endif
