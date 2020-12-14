/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:00:51 by tlemesle          #+#    #+#             */
/*   Updated: 2020/12/11 18:57:46 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

int	ft_is_int_convertor(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' \
	|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	ft_is_other_convertor(char c)
{
	if (c == 'c' || c == 's' || c == 'p' \
	||  c == '%')
		return (1);
	return (0);
}

int	ft_is_convertor(char c)
{
	if (ft_is_int_convertor(c) || ft_is_other_convertor(c))
		return (1);
	return (0);
}