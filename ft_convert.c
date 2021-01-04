/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:18:29 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/04 11:19:52 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
 
char	*ft_char_convert(char c, va_list ap)
{
	char	*ptr;

//	if (c == 'c')
//		ptr = (char) va_arg(ap, char);
//	else
	if (c == 's')
		ptr = (char *) va_arg(ap, char *);
	else
		ptr = 0;
	return (ptr);
}
/*
char	*ft_int_convert(char c, va_list ap)
{

}

char	*ft_hexa_convert(char c, va_list ap)
{

}

char	*ft_other_convert(char c, va_list ap)
{

}
*/
int	ft_convert(char c, t_flags flags, va_list ap)
{
	char	*arg;
	int		count;

	count = 0;
	if (ft_is_char_convertor(c))
		arg = ft_char_convert(c, ap);
	else
		arg = 0;
//	if (ft_is_int_convertor(c))
//		arg = ft_int_convert(c, ap);
//	if (ft_is_hexa_convertor(c))
//		arg = ft_hexa_convert(c, ap);
//	if (ft_is_other_convertor(c))
//		arg = ft_other_convert(c, ap);
//	printf("[Arg sent to flag_trad] : %s\n", arg);
	arg = ft_flag_trad(arg, flags, c);
	count = ft_putn_and_count(arg, ft_strlen(arg));
	return (count);
}