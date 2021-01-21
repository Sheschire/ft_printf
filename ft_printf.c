/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:45:15 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/21 09:10:17 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fill_flags(char *s, va_list *ap)
{
	t_flags flags;
	int	i;
	int count;

	i = 0;
	flags = ft_init_flags();
	while (s[i] && !ft_is_convertor(s[i]))
	{
		if (s[i] == '0') //&& flags.minus == 0 && flags.dot == -1)
			flags.zero = 1;
		if (s[i] == '.')
			flags = ft_dot_flag(flags, s + i);
		if (ft_isdigit(s[i]) && s[i] != '0')
			flags.width = ft_atoi(&s[i]);
		if (flags.dot != -1 || flags.width != 0)
			i += ft_update_index(s + i, flags);
		if (s[i] == '-')
			flags = ft_minus_flag(flags, s + i);
		if (s[i] == '*')
			flags = ft_joker_flag(flags, *ap);
		i++;
	}
	flags.convertor = s[i];
	if (flags.zero == 1)
		flags = ft_zero_flag(flags, s + i);
	if (s[i] && ft_is_convertor(s[i]))
		count = ft_convert(s[i], flags, *ap);
	else
		count = 0;
	return (count);
}

int	ft_putn_and_count(char *s, int n)
{
	write(1, s, n);
	return (n);
}

int	ft_build_print(char *s, va_list *ap)
{
	char	*tmp;
	int		count;

	count = 0;
	while (*s)
	{
		tmp = s;
		while (*s != '%' && *s)
			s++;
		if (*s == '%')
		{
			if (tmp != s)
				count += ft_putn_and_count(tmp, (s - tmp));
			count += ft_fill_flags(s + 1, ap);
			s++;
			while (ft_is_flag(*s) && *s)
				s++;
			if (ft_is_convertor(*s))
				s++;
			if (!*s)
				return (count);
		}
	}
	count += ft_putn_and_count(tmp, (s - tmp));
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list ap;
	int		count;

	va_start(ap, input);
	if (!input)
		return (0);
	count = ft_build_print((char *)input, &ap);
	va_end(ap);
	return (count);
}
