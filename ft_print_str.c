/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:01:03 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/07 13:27:13 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calculate_malloc(t_flags flags, char * arg, char c)
{
	int	len;

	if (flags.width == 0 && flags.dot != -1)
	{
		if (ft_is_char_convertor(c))
		{
			if ((size_t)flags.dot < ft_strlen(arg))
				len = flags.dot;
			else
				len = ft_strlen(arg) - 1;
		}
		if (ft_is_int_convertor(c))
		{
			if ((size_t)flags.dot < ft_strlen(arg))
				len = ft_strlen(arg) - 1;
			else
				len = flags.dot;
		}
	}
	if (flags.width != 0 && ft_strlen(arg) < (size_t)flags.width)
		len = flags.width;
	if (flags.width != 0 && ft_strlen(arg) > (size_t)flags.width)
		len = ft_strlen(arg) - 1;
	return (len);
}

char	*ft_check_width_minus(char *arg, char *res, t_flags flags, int len, int i)
{
	if (flags.dot != -1)
		while (++i < flags.dot && (size_t)i < ft_strlen(arg))
			res[i] = arg[i];
	else
		while (arg[++i])
			res[i] = arg[i];
	if (ft_strlen(arg) > (size_t)flags.width)
		return (res);
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

int	ft_print_str(char *arg, t_flags flags, char c)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = ft_calculate_malloc(flags, arg, c);
	res = (char *)malloc(sizeof(char *) * len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	res = ft_check_width_minus(arg, res, flags, len, i);
	len = ft_putn_and_count(res, ft_strlen(res));
	free (res);
	return (len);
}

char	*ft_check_width(t_flags flags, int arg, char *res)
{
	int	count;

	count = 0;
	if (flags.width == 0)
	{
		write(1, &arg, 1);
		count++;
	}
	else
	{
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
	}
	return (res);
}

int		ft_print_char(va_list ap, t_flags flags)
{
	int		arg;
	int		count;
	char	*res;

	arg = (int) va_arg(ap, int);
	res = (char *)malloc(sizeof(char *) * flags.width + 1);
	if (!res)
		return (0);
	res[flags.width] = '\0';
	res = ft_check_width(flags, arg, res);
	count = ft_putn_and_count(res, ft_strlen(res));
	free(res);
	return (count);
}