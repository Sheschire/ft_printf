/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:01:03 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/16 11:19:10 by tlemesle         ###   ########.fr       */
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
		return (0);
	res[len] = '\0';
	res = ft_check_flags_char(arg, res, flags, len, i);
	len = ft_putn_and_count(res, ft_strlen(res));
	free(res);
	return (len);
}

char	*ft_check_width(t_flags flags, int arg, char *res)
{
	int	count;

	count = 0;
	if (flags.minus == 0)
	{
		res[flags.width - 1] = arg;
		while (count < flags.width - 1)
			res[count++] = ' ';
		count++;
	}
	else
	{
		res[count] = arg;
		while (count < flags.width - 1)
			res[++count] = ' ';
	}
	return (res);
}

int		ft_print_char(char c, va_list ap, t_flags flags)
{
	int		arg;
	int		count;
	char	*res;
	int		len;

	if (c == '%')
		arg = 37;
	else
		arg = (int) va_arg(ap, int);
	if (flags.width != 0)
		len = flags.width;
	else
	{
		write(1, &arg, 1);
		return (count = 1);
	}
	
	res = (char *)malloc(sizeof(char *) * len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	res = ft_check_width(flags, arg, res);
	count = ft_putn_and_count(res, ft_strlen(res));
	free(res);
	return (count);
}