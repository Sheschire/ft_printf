/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_trad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:01:03 by tlemesle          #+#    #+#             */
/*   Updated: 2020/12/18 15:06:37 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_calculate_malloc(t_flags flags, char * arg, char c)
{
	int	res;

	if (flags.width == 0 && flags.dot != -1)
	{
		if (c == 's')
		{
			if ((size_t)flags.dot < ft_strlen(arg))
				res = flags.dot;
			else
				res = ft_strlen(arg);
		}
		if (ft_is_int_convertor(c))
		{
			if ((size_t)flags.dot < ft_strlen(arg))
				res = ft_strlen(arg);
			else
				res = flags.dot;
		}
	}
	if (flags.width != 0)
		res = flags.width;
	return (res);
}

char	*ft_flag_trad(char *arg, t_flags flags, char c)
{
	char	*res;
	int		len;
	int		i;

	len = ft_calculate_malloc(flags, arg, c);
	res = (char *)malloc(sizeof(char *) * len + 1);
	res[len] = '\0';
	if (flags.dot != -1)
	{
		i = flags.dot;
		while (i >= 0)
		{
			if (flags.minus == 0)
			{
				len--;
				i--;
				res[len] = arg[i];
			}
			else
			{
				i--;
				res[i] = arg[i];
			}
		}
	}
	i = flags.dot;
	if (flags.width != 0)
	{
		if (flags.minus == 0)
		{
			while (len >= 0)
			{
				res[len] = ' ';
				len--;
			}
		}
		else
		{
			while (len > i)
			{
				len--;
				res[len] = ' ';
			}
		}
	}
/*	printf("res = %c\n", res[0]);
	printf("res = %c\n", res[1]);
	printf("res = %c\n", res[2]);
	printf("res = %c\n", res[3]);
	printf("res = %c\n", res[4]);
	printf("res = %c\n", res[5]);
	printf("res = %c\n", res[6]);
	printf("res = %c\n", res[7]);
	printf("res = %c\n", res[8]);
*/
//	printf("res = %s\n", res);
	return (res);
}