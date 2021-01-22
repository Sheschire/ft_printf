/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:15:22 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/21 15:31:51 by tlemesle         ###   ########.fr       */
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
	return (flags);
}

t_flags	ft_minus_flag(t_flags flags, char *s)
{
	if ((ft_isdigit(*(s + 1)) || *(s + 1) == '*') && flags.width == 0)
		flags.minus = 1;
	return (flags);
}

t_flags	ft_zero_flag(t_flags flags, char *s)
{
	if (flags.zero == 1)
	{
		if (flags.minus == 1)
			flags.zero = 0;
		if (flags.dot != -1)
		{
			flags.zero = 0;
			if (*s == '%')
				flags.zero = 1;
		}
	}
	return (flags);
}

t_flags	ft_joker_flag(t_flags flags, va_list ap)
{
	flags.joker = (int)va_arg(ap, int);
	if (flags.dot == '*')
	{
		flags.dot = flags.joker;
		if (flags.dot < 0)
			flags.dot = -1;
	}
	else
	{
		if (flags.joker < 0)
		{
			flags.minus = 1;
			flags.width = flags.joker * -1;
		}
		else
			flags.width = flags.joker;
	}
	return (flags);
}

int		ft_update_index(char *s, t_flags flags)
{
	int		i;
	char	*itoa_width;

	i = 0;
	itoa_width = NULL;
	if (flags.width != 0 && s[i] != '.' && s[i] != '*')
	{
		itoa_width = ft_itoa(flags.width);
		i = ft_strlen(itoa_width) - 1;
		free(itoa_width);
	}
	if (flags.dot != -1)
		while (ft_isdigit(s[i + 1]))
			i++;
	return (i);
}
