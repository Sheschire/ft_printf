/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:34:23 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/21 10:40:05 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_sign2(char *res, int len, t_flags flags, int arglen)
{
	if (flags.width == (int)ft_strlen(res) && flags.width == flags.dot)
	{
		res = ft_strjoin("-", res);
		return (res);
	}
	if (flags.dot > flags.width && flags.dot > arglen)
	{
		res = ft_strjoin("-", res);
		return (res);
	}
	while (res[len - 1] == ' ')
		len--;
	if (flags.width == arglen + 1)
		len--;
	if (flags.width == flags.dot + 1 && flags.dot > arglen)
		len--;
	while (len >= 0)
	{
		res[len + 1] = res[len];
		len--;
	}
	res[len + 1] = '-';
	return (res);
}

char	*ft_put_sign(char *res, t_flags flags, int arglen, int len)
{
	if (flags.zero == 1 && flags.error == 0)
	{
		if (flags.width == 0 || flags.width <= arglen)
			res = ft_strjoin("-", res);
		else
			res[0] = '-';
	}
	if (flags.minus == 0)
	{
		if (flags.width <= arglen && (flags.zero == 0 || flags.error == 1))
			res = ft_strjoin("-", res);
		if (flags.dot >= flags.width && flags.dot > arglen && flags.width != 0)
			return (res = ft_strjoin("-", res));
		if (flags.width > arglen && (flags.zero == 0 || flags.error == 1))
		{
			while (res[len] != ' ')
				len--;
			res[len] = '-';
			if (flags.width == arglen + 1 && flags.dot > arglen)
				res = ft_strjoin("-", res);
		}
	}
	else
		res = ft_put_sign2(res, len, flags, arglen);
	return (res);
}

char	*ft_width_int(char *res, t_flags flags, int len, int i)
{
	if (flags.minus == 0)
	{
		i--;
		while (i >= 0)
			res[len-- - 1] = res[i--];
		while (len > 0)
		{
			if (flags.zero == 1 && flags.arglen != 0 && flags.error == 0)
				res[--len] = '0';
			else
				res[--len] = ' ';
		}
	}
	else
		while (i < len)
			res[i++] = ' ';
	return (res);
}

char	*ft_check_flags_int(char *arg, char *res, t_flags flags, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	flags.arglen = (int)ft_strlen(arg);
	if (flags.dot != -1)
		while (i < flags.dot - flags.arglen)
			res[i++] = '0';
	while (arg[j])
		res[i++] = arg[j++];
	if (flags.width != 0)
		ft_width_int(res, flags, len, i);
	if (flags.intneg == 1)
		res = ft_put_sign(res, flags, flags.arglen, len);
	return (res);
}

int		ft_print_int(char *arg, t_flags flags)
{
    char	*res;
	int		len;

	len = ft_int_malloc(arg, flags);
	res = (char *)malloc(sizeof(char *) * len);
	if (!res)
		return (-1);
	res[len] = '\0';
	res = ft_check_flags_int(arg, res, flags, len);
	len = ft_putn_and_count(res, ft_strlen(res));
	free(res);
	return (len);
}
