/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:00:24 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/20 15:26:59 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_malloc(t_flags flags, char * arg)
{
	int	len_str;
	int	len_res;

	if ((size_t)flags.dot < ft_strlen(arg) && flags.dot != -1)
		len_str = flags.dot;
	else
		len_str = ft_strlen(arg);
	if (flags.width != 0 && len_str <= flags.width)
		len_res = flags.width;
	if (flags.width != 0 && len_str > flags.width)
		len_res = len_str;
	if (flags.width == 0)
		len_res = len_str;
	return (len_res);
}

int		ft_int_malloc(char *arg, t_flags flags)
{
	int	arglen;
	int	len;

	len = 0;
	arglen = (int)ft_strlen(arg);
	if (arglen >= flags.dot && arglen >= flags.width)
			return (arglen);
	if (flags.dot > arglen || flags.dot >= flags.width)
			len = flags.dot;
	if (flags.width > flags.dot && flags.width > arglen)
		len = flags.width;
	return (len);
}