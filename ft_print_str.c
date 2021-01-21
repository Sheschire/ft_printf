/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:01:03 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/21 10:21:54 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_flags_char(char *arg, char *res, t_flags flags, int len, int i)
{
	if (flags.dot != -1)
		while (++i < flags.dot && (size_t)i < ft_strlen(arg))
			res[i] = arg[i];
	else
		while (arg[++i])
			res[i] = arg[i];
	if (flags.width != 0)
	{
		if (flags.minus == 0)
		{
			i--;
			while (i >= 0)
				res[len-- - 1] = res[i--];
			while (len > 0)
				res[--len] = ' ';
		}
		else
			while (i < len)
				res[--len] = ' ';
	}
	return (res);
}

int	ft_print_str(char *arg, t_flags flags)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = ft_str_malloc(flags, arg);
	res = (char *)malloc(sizeof(char *) * len + 1);
	if (!res)
		return (-1);
	res[len] = '\0';
	res = ft_check_flags_char(arg, res, flags, len, i);
	len = ft_putn_and_count(res, ft_strlen(res));
	free(res);
	return (len);
}

int		ft_put_width(char c, t_flags flags, int arg)
{
	int	i;

	i = 0;
	if (flags.minus == 0)
	{
		while (i++ < flags.width - 1)
		{
			if (c == '%' && flags.zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		write(1, &arg, 1);
		return (i);
	}
	else
	{
		write(1, &arg, 1);
		while (i++ < flags.width - 1)
			write(1, " ", 1);
		return (i);
	}
}

int		ft_print_char(char c, va_list ap, t_flags flags)
{
	int		arg;
	int		i;

	i = 0;
	if (c == '%')
		arg = 37;
	else
		arg = (int) va_arg(ap, int);
	if (flags.width > 1)
		return (ft_put_width(c, flags, arg));
	write(1, &arg, 1);
	return (1);
}