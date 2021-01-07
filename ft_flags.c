/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:15:22 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/07 10:32:40 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

t_flags	ft_dot_flag(t_flags flags, char *s)
{
	if (!ft_isdigit(*(s + 1)) || *(s + 1) == '-')
		flags.dot = -1;
	if (ft_isdigit(*(s + 1)))
		flags.dot = ft_atoi(s + 1);
	if (*(s + 1) == '*')
		flags.dot = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_minus_flag(t_flags flags, char *s)
{
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

t_flags	ft_joker_flag(t_flags flags, va_list ap)
{
	if (flags.dot == 1)
		flags.dot = (int) va_arg(ap, int);
	else
		flags.width = (int) va_arg(ap, int);
	return (flags);
}

int	ft_update_index(char *s, char c, t_flags flags)
{
	int	i;

	i = 0;
	if (ft_isdigit(c))
		i = ft_strlen(ft_itoa(flags.width)) - 1;
	else
	{
		while (ft_isdigit(s[i] + 1))
			i++;
		i++;
	}
	return (i);
}
