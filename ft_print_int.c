/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:34:23 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/12 12:54:31 by tlemesle         ###   ########.fr       */
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
			res[--len] = ' ';
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
	if (ft_strlen(arg) >= (size_t)flags.width)
		return (res);
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
	free(res);
	return (len);
}