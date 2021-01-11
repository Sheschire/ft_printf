/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:01:03 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/11 18:13:34 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calculate_malloc(t_flags flags, char * arg, char c)
{
	int	len_str;
	int	len_res;

	if (ft_is_char_convertor(c))
	{
		if ((size_t)flags.dot < ft_strlen(arg))
			len_str = flags.dot;
		else
			len_str = ft_strlen(arg);
	}
	if (ft_is_int_convertor(c))
	{
		if ((size_t)flags.dot < ft_strlen(arg))
			len_str = ft_strlen(arg);
		else
			len_str = flags.dot;
	}
	if (flags.width != 0 && len_str <= flags.width)
		len_res = flags.width;
	if (flags.width != 0 && len_str > flags.width)
		len_res = len_str;
	return (len_res);
}

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

int	ft_print_str(char *arg, t_flags flags, char c)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = ft_calculate_malloc(flags, arg, c);
	printf("len = %d\n", len);
	res = (char *)malloc(sizeof(char *) * len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	res = ft_check_flags_char(arg, res, flags, len, i);
	len = ft_putn_and_count(res, ft_strlen(res));
//	free(res);
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

int		ft_print_char(char c, va_list ap, t_flags flags)
{
	int		arg;
	int		count;
	char	*res;

	if (c == '%')
		arg = 37;
	else
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