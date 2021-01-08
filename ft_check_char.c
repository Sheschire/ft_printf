/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:00:51 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/08 17:10:13 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_int_convertor(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	return (0);
}

int	ft_is_hexa_convertor(char c)
{
	if (c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

int	ft_is_char_convertor(char c)
{
	if (c == 'c' || c == 's')
		return (1);
	return (0);
}

int	ft_is_other_convertor(char c)
{
	if (c == 'p' || c == '%')
		return (1);
	return (0);
}

int	ft_is_convertor(char c)
{
	if (ft_is_int_convertor(c) || ft_is_char_convertor(c) \
	|| ft_is_hexa_convertor(c) || ft_is_other_convertor(c))
		return (1);
	return (0);
}

int	ft_is_flag(char c)
{
	if (c == '.' || c == '-' || c == '*' || ft_isdigit(c))
		return(1);
	return (0);
}