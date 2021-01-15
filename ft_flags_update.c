/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:15:22 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/15 12:05:27 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_dot_flag(t_flags flags, char *s)
{
	if (*(s + 1) == '-' || !ft_isdigit(*(s + 1)))
		flags.error = 1;
	if (ft_isdigit(*(s + 1)))
		flags.dot = ft_atoi(s + 1);
	if (*(s + 1) == '*')
	{
		flags.dot = '*';
		flags.error = 0;
	}
	flags.zero = 0;
	return (flags);
}

t_flags	ft_minus_flag(t_flags flags, char *s)
{
	if ((ft_isdigit(*(s + 1)) || *(s + 1) == '*') && flags.width == 0)
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
	if (flags.dot == '*')
	{
		flags.dot = (int) va_arg(ap, int);
		if (flags.dot < 0)
			flags.dot = -1;
	}
	else
		flags.width = (int) va_arg(ap, int);
	return (flags);
}

int	ft_update_index(char *s, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.width != 0 && s[i] != '.')
		i = ft_strlen(ft_itoa(flags.width)) - 1;
	if (flags.dot != -1)
		while (ft_isdigit(s[i + 1]))
			i++;
	return (i);
}
