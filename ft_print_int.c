/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:34:23 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/13 15:30:58 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_width_int(char *res, t_flags flags, int len, int i)
{
	if (flags.minus == 0)
	{
		i--;
		while (i >= 0)
			res[len-- - 1] = res[i--];
		while (len > 0)
		{
			if (flags.zero == 1)
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

char	*ft_int_neg(char *res, char *arg, t_flags flags)
{
	int	j;

	j = 1;
	if (flags.zero == 1 && flags.width > (int)ft_strlen(arg))
	{
		res[0] = '-';
		while (res[j] == '0')
			j++;
		res[j] = '0';
	}
	if (flags.dot > (int)ft_strlen(arg) - 1)
	{
		while (res[j] == '0')
			j++;
		res[j] = '0';
		if (flags.width > flags.dot)
		{
			if (flags.minus == 0)
			{
				while (++flags.dot < flags.width)
					write(1, " ", 1);
				write(1, "-", 1);
			}
			else
				write(1, "-", 1);
		}
		else
		{
			write(1, "-", 1);
		}
		
	}
	return (res);
}

char	*ft_check_flags_int(char *arg, char *res, t_flags flags, int len)
{
	int	i;
    int j;

	i = 0;
    j = 0;
	if (flags.dot != -1)
		while (i < flags.dot - (int)ft_strlen(arg))
			res[i++] = '0';
	while (arg[j])
		res[i++] = arg[j++];
	if (ft_strlen(arg) >= (size_t)flags.width && flags.dot <= (int)ft_strlen(arg) - 1)
		return (res);
	if (flags.width != 0 && flags.dot == -1)
		ft_check_width_int(res, flags, len, i);
	if (flags.intneg == 1)
		return (ft_int_neg(res, arg, flags));
	if (flags.width != 0)
		ft_check_width_int(res, flags, len, i);
	return (res);
}

int		ft_print_int(char *arg, t_flags flags, char c)
{
    char	*res;
	int		len;

	len = ft_calculate_malloc(flags, arg, c);
	res = (char *)malloc(sizeof(char *) * len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	res = ft_check_flags_int(arg, res, flags, len);
	len = ft_putn_and_count(res, ft_strlen(res));
	if (flags.dot > (int)ft_strlen(arg) - 1 && flags.intneg == 1 && flags.width < flags.dot)
		len++;
	if (flags.dot > (int)ft_strlen(arg) - 1 && flags.intneg == 1 && flags.width > flags.dot)
		len += flags.width - flags.dot;
	free(res);
	return (len);
}