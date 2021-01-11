/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:18:29 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/11 14:12:56 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pointer_convert(char c, va_list ap, t_flags flags)
{
	void			*arg;

	arg = (void *) va_arg(ap, void *);
	arg = ft_u_itoa((unsigned long long)arg, c);
	if (ft_is_flags_empty(flags))
		return (ft_putn_and_count(arg, ft_strlen(arg)));
	else
		return (ft_print_int(arg, flags, c));
	return (0);
}

int		ft_hexa_convert(char c, va_list ap, t_flags flags)
{
	char			*arg;
	unsigned int	u_nb;

	u_nb = (unsigned int) va_arg(ap, unsigned int);
	if (flags.dot == 0 && u_nb == 0)
	{
		write(1, "", 1);
		return (0);
	}
	arg = ft_u_itoa(u_nb, c);
	if (ft_is_flags_empty(flags))
		return (ft_putn_and_count(arg, ft_strlen(arg)));
	else
		return (ft_print_int(arg, flags, c));
	free(arg);
	return (0);
}

int	ft_int_convert(char c, va_list ap, t_flags flags)
{
	char			*arg;
	int				count;

	count = (int) va_arg(ap, int);
	if (flags.dot == 0 && count == 0)
	{
		write(1, "", 1);
		return (0);
	}
	arg = ft_itoa(count);
	if (ft_is_flags_empty(flags))
		return (ft_putn_and_count(arg, ft_strlen(arg)));
	else
		return (ft_print_int(arg, flags, c));
	free(arg);
	return (0);
}

int		ft_char_convert(char c, va_list ap, t_flags flags)
{
	char	*arg;
	
	if (c == 's')
	{
		arg = (char *) va_arg(ap, char *);
		if (arg == NULL)
			arg = "(null)";	
		if (ft_is_flags_empty(flags))
			return (ft_putn_and_count(arg, ft_strlen(arg)));
		else
			return(ft_print_str(arg, flags, c));
	}
	if (c == 'c' || c == '%')
	{
		if (ft_is_flags_empty(flags))
			return (ft_print_char(c, ap, flags) + 1);
		return (ft_print_char(c, ap, flags));
	}
	return (0);
}

int	ft_convert(char c, t_flags flags, va_list ap)
{
	if (ft_is_char_convertor(c))
		return (ft_char_convert(c, ap, flags));
	if (ft_is_int_convertor(c))
		return(ft_int_convert(c, ap, flags));
	if (ft_is_hexa_convertor(c))
		return(ft_hexa_convert(c, ap ,flags));
	if (c == 'p')
		return (ft_pointer_convert(c, ap, flags));
	return (0);
}