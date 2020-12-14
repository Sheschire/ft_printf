/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:15:22 by tlemesle          #+#    #+#             */
/*   Updated: 2020/12/11 18:57:46 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

t_flags	ft_dot_flag(t_flags flags, char *s)
{
	if (!ft_isdigit(*(s + 1)) || *(s + 1) == '-')
		flags.dot = -1;
	if (ft_isdigit(*(s + 1)))
		flags.dot = ft_atoi(*(s + 1));
	flags.zero = 0;
	return (flags);
}

t_flags	ft_minus_flag(t_flags flags, char *s)
{
	if (!ft_isdigit(*(s + 1)))
		flags.minus = 0;
	if (ft_isdigit(*(s + 1)) && flags.width == 0)
		flags.minus = 1; 
	flags.zero = 0;
	return (flags);
}

t_flags	ft_width_flag(t_flags flags, char *s)
{
	flags.width = ft_atoi(s);
	return (flags);
}
/*
int	ft_joker_flag(t_flags flags)
{

}*/

int	ft_update_index(char *s, char c, t_flags flags)
{
	int	i;

	i = 0;
	if (ft_isdigit(c))
		i = ft_strlen(ft_itoa(flags.width));
	else
	{
		while (ft_isdigit(s[i] + 1))
			i++;
		i++;
	}
	return (i);
}
/*
static void	ft_print_str(va_list ap)
{
	char *ptr;

	ptr = (char *) va_arg(ap, char *);
	write(1, ptr, ft_strlen(ptr));
}

static void	ft_print_int(va_list ap)
{
	int ptr;
	char *str;

	ptr = (int) va_arg(ap, int);
	str = ft_itoa(ptr);
	write(1, str, ft_strlen(str));
}

static void	ft_print_convertor(va_list ap, char c)
{
	if (c == 's')
		ft_print_str(ap);
	if (c == 'd')
		ft_print_int(ap);
}*/