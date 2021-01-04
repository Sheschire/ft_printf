/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:44:25 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/04 11:22:19 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H

#  define FT_PRINTF_H

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
	char	convertor;
}					t_flags;

t_flags	ft_dot_flag(t_flags flags, char *s);
t_flags	ft_minus_flag(t_flags flags, char *s);
t_flags	ft_width_flag(t_flags flags, char *s);
int		ft_update_index(char *s, char c, t_flags flags);
int		ft_is_int_convertor(char c);
int		ft_is_char_convertor(char c);
int		ft_is_hexa_convertor(char c);
int		ft_is_other_convertor(char c);
int		ft_is_convertor(char c);
int		ft_convert(char c, t_flags flags, va_list ap);
char	*ft_char_convert(char c, va_list ap);
char	*ft_int_convert(char c, va_list ap);
char	*ft_hexa_convert(char c, va_list ap);
char	*ft_other_convert(char c, va_list ap);
char	*ft_flag_trad(char *arg, t_flags flags, char c);
int		ft_putn_and_count(char *s, int n);
int		ft_calculate_malloc(t_flags flags, char * arg, char c);

# endif